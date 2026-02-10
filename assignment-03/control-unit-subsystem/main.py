import time, sys, threading, serial, json
from collections import deque
import paho.mqtt.client as mqtt
from flask import Flask, jsonify, request
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

# Configuration constants
CONFIG_CONSTANTS = {
    "L1": 70,  # Lower water level threshold
    "L2": 90,  # Upper water level threshold
    "T1": 10,  # Time threshold for valve adjustment
    "MQTT_TIMEOUT": 6,  # MQTT connection timeout
    "MQTT_KEEPALIVE": 60,
}

config_lock = threading.Lock()
config = {"waterLevel": 0, "valveValue": 0, "state": "UNCONNECTED"}
last_message_time = time.time()
automatic = False
connected = False
serial_outbox = deque()
above_L1_since = None


def mqtt_worker(broker, topic):
    global config, last_message_time, automatic, connected, config_lock

    def on_message(client, userdata, msg):
        global connected, last_message_time
        with config_lock:
            last_message_time = time.time()
            config["waterLevel"] = msg.payload.decode(errors="ignore").strip()
            connected = True

    while True:
        client = None
        try:
            client = mqtt.Client()
            client.on_message = on_message  # Set callback before connecting
            client.connect(broker, 1883, CONFIG_CONSTANTS["MQTT_KEEPALIVE"])
            client.subscribe(topic)
            client.loop_start()
            print("MQTT connected.")

            while True:
                with config_lock:
                    if (
                        time.time() - last_message_time
                        > CONFIG_CONSTANTS["MQTT_TIMEOUT"]
                    ):
                        if connected:
                            connected = False

                time.sleep(1)
        except (ConnectionRefusedError, OSError):
            print("MQTT disconnected. Reconnecting...")
            connected = False
            time.sleep(1)
        finally:
            if client is not None:
                client.loop_stop()
                client.disconnect()


def serial_worker(port, baudrate):
    global config, automatic, connected, config_lock, above_L1_since
    L1 = CONFIG_CONSTANTS["L1"]
    L2 = CONFIG_CONSTANTS["L2"]
    T1 = CONFIG_CONSTANTS["T1"]

    while True:
        ser = None
        try:
            ser = serial.Serial(port, baudrate, timeout=1)
            print("WCS connected.")
            while True:
                line = ser.readline().decode(errors="ignore").strip()

                # Acquire lock once for all state updates
                with config_lock:
                    is_connected = connected
                    if line in {"UNCONNECTED", "AUTOMATIC", "MANUAL"}:
                        automatic = True if line == "AUTOMATIC" else False
                        config["state"] = line

                    if line.isdigit():
                        config["valveValue"] = line

                    pending = list(serial_outbox)
                    serial_outbox.clear()

                # Write operations outside lock (ser.write is not thread-safe with config anyway)
                ser.write(b"C\n" if is_connected else b"U\n")

                for cmd in pending:
                    ser.write(cmd)

                # Automatic mode logic with consolidated lock
                if automatic and is_connected:
                    with config_lock:
                        try:
                            water_level = float(config["waterLevel"])

                            if water_level >= L2:
                                valve_cmd = b"100\n"
                                above_L1_since = None
                            elif water_level >= L1:
                                if above_L1_since is None:
                                    above_L1_since = time.time()

                                if time.time() - above_L1_since > T1:
                                    valve_cmd = b"50\n"
                                else:
                                    valve_cmd = None
                            else:
                                valve_cmd = b"0\n"
                                above_L1_since = None

                            if valve_cmd:
                                ser.write(valve_cmd)
                        except (ValueError, KeyError):
                            pass  # Invalid water level data
        except (serial.SerialException, OSError):
            print("WCS disconnected. Reconnecting...")
            time.sleep(1)
        finally:
            if ser is not None:
                ser.close()


@app.route("/api/data", methods=["GET"])
def get_data():
    with config_lock:
        return jsonify(config)


@app.route("/api/mode", methods=["POST"])
def set_mode():
    payload = request.get_json(silent=True) or {}
    state = payload.get("state")
    valveValue = payload.get("valveValue")

    if state not in {"AUTOMATIC", "MANUAL"}:
        return jsonify({"error": "invalid state"}), 400

    # Validate valveValue if provided and not -1
    if valveValue not in ("-1", None):
        try:
            valve_int = int(valveValue)
            if not 0 <= valve_int <= 100:
                return jsonify({"error": "valveValue must be between 0 and 100"}), 400
        except (ValueError, TypeError):
            return jsonify({"error": "valveValue must be a number"}), 400

    with config_lock:
        if config["state"] != state:
            config["state"] = state
            serial_outbox.append(b"M\n")

        if valveValue != "-1":
            config["valveValue"] = valveValue
            serial_outbox.append(valveValue.encode() + b"\n")
    return jsonify({"ok": True})


def run(
    port,
    baud=9600,
    broker="broker.mqtt-dashboard.com",
    topic="SmartTank/esp32/backend",
):
    try:
        threading.Thread(target=serial_worker, args=(port, baud), daemon=True).start()
        threading.Thread(target=mqtt_worker, args=(broker, topic), daemon=True).start()
        app.run(host="0.0.0.0", port=8080, threaded=True)
    except KeyboardInterrupt:
        print("\nShutting down...")


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python main.py <port>")
        sys.exit(1)

    run(sys.argv[1])
