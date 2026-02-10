import time, sys, threading, serial, json
from collections import deque
import paho.mqtt.client as mqtt
from flask import Flask, jsonify, request
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

config_lock = threading.Lock()
config = {"waterLevel": 0, "valveValue": 0, "state": "UNCONNECTED"}
last_message_time = time.time()
automatic = False
connected = False
serial_outbox = deque()

L1, L2 = 70, 90
T1 = 10
above_L1_since = None


def mqtt_worker(broker, topic):
    global config, last_message_time, automatic, connected, config_lock

    def on_message(client, userdata, msg):
        global connected, last_message_time
        with config_lock:
            last_message_time = time.time()
            connected = True
            config["waterLevel"] = msg.payload.decode(errors="ignore").strip()

    while True:
        client = None
        try:
            client = mqtt.Client()
            client.connect(broker, 1883, 60)
            client.subscribe(topic)
            client.loop_start()
            print("MQTT connected.")

            client.on_message = on_message
            while True:
                with config_lock:
                    if time.time() - last_message_time > 6:
                        if connected:
                            connected = False

                time.sleep(1)
        except (ConnectionRefusedError, OSError):
            print("MQTT disconnected. Reconnecting...")
            with config_lock:
                connected = False
            time.sleep(1)
        finally:
            if client is not None:
                client.loop_stop()
                client.disconnect()


def serial_worker(port, baudrate):
    global config, automatic, connected, config_lock, above_L1_since
    while True:
        ser = None
        try:
            ser = serial.Serial(port, baudrate, timeout=1)
            print("WCS connected.")
            while True:
                line = ser.readline().decode(errors="ignore").strip()

                with config_lock:
                    if line in {"UNCONNECTED", "AUTOMATIC", "MANUAL"}:
                        automatic = True if line == "AUTOMATIC" else False
                        config["state"] = line

                    if line.isdigit():
                        config["waterLevel"] = line 

                    ser.write(b"C\n" if connected else b"U\n")

                    pending = list(serial_outbox)
                    serial_outbox.clear()

                for cmd in pending:
                    ser.write(cmd)

                if automatic and connected:
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

    with config_lock:
        if config["state"] != state:
            config["state"] = state
            config["valveValue"] = valveValue
            serial_outbox.append(b"M\n")

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
