import serial, time, sys, threading
import paho.mqtt.client as mqtt
from flask import Flask, jsonify
from flask_cors import CORS

mqtt_client = mqtt.Client()

app = Flask(__name__)
CORS(app)

def mqtt_connect(mqtt_broker, mqtt_topic):
    try:
        while True:
            try:
                mqtt_client.connect(mqtt_broker, 1883, 60)
                mqtt_client.subscribe(mqtt_topic)
                mqtt_client.loop_start()
                print(f"Connected to MQTT broker: {mqtt_broker}")
                print(f"Subscribed to topic: {mqtt_topic}")
                return
            except Exception as e:
                print(f"MQTT connection failed: {e}")
                time.sleep(1)
    finally:
        mqtt_client.loop_stop()
        mqtt_client.disconnect()

def connect(port, baudrate):
    while True:
        try:
            ser = serial.Serial(port, baudrate, timeout=1)
            time.sleep(2)
            print(f"Connected to {port}")
            return ser
        except Exception as e:
            print(f"Connection attempt failed: {e}")
            time.sleep(1)

def serial_listener(port, baudrate):
    ser = connect(port, baudrate)
    
    try:
        while True:
            try:
                line = ser.readline().decode(errors="ignore").strip()
                if line:
                    print(f"Received: {line}")
            except (serial.SerialException, OSError):
                print("Device disconnected. Reconnecting...")
                ser.close()
                ser = connect(port, baudrate)
    finally:
        ser.close()


@app.route("/")
def index():
    return "Serial Web Server active"

@app.route("/data")
def get_data():
    return jsonify({"latest": ""})

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python main.py <port> <baudrate>")
        sys.exit(1)

    L1, L2, T1, T2 = 40.0, 70.0, 5.0, 10.0

    threading.Thread(target=mqtt_connect, args=("broker.mqtt-dashboard.com", "SmartTank/esp32/backend"), daemon=True).start()
    threading.Thread(target=serial_listener, args=(sys.argv[1], int(sys.argv[2])), daemon=True).start()
    
    print("Starting Flask server...")
    try:
        app.run(host="0.0.0.0", port=8080, debug=False, use_reloader=False)
    except KeyboardInterrupt:
        print("\nShutting down...")
    finally:
        time.sleep(0.5)
