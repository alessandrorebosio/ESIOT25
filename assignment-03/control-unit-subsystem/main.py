import serial, time, sys, threading
import paho.mqtt.client as mqtt
from flask import Flask, jsonify, request
from flask_cors import CORS

data_store = {
    "waterLevel": 0,
    "valveLevel": 0,
    "state": "AUTOMATIC",
    "controlType": "none"
}
data_lock = threading.Lock()
ser = None

app = Flask(__name__)
CORS(app)

def on_message(client, userdata, message):
    global data_store
    try:
        payload = message.payload.decode("utf-8")
        with data_lock:
            data_store["waterLevel"] = float(payload)
    except Exception as e:
        print(f"MQTT parsing error: {e}")

def mqtt_worker():
    client = mqtt.Client()
    client.on_message = on_message
    try:
        client.connect("broker.mqtt-dashboard.com", 1883)
        client.subscribe("SmartTank/esp32/backend")
        client.loop_forever()
    except:
        time.sleep(5)

def serial_worker(port, baudrate):
    global ser
    while True:
        try:
            ser = serial.Serial(port, baudrate, timeout=1)
            print(f"Serial Connected: {port}")
            while True:
                line = ser.readline().decode(errors="ignore").strip()
                if line == "AUTOMATIC" or line == "MANUAL" :
                    with data_lock:
                        data_store["state"] = line
                        data_store["controlType"] = "auto"
                if line.isDigit():
                    with data_lock:
                        data_store["valveLevel"] = line
                if line:
                    print(f"Reveived: {line}")
        except:
            print("Serial lost, reconnection...")
            time.sleep(2)

@app.route("/api/data", methods=["GET"])
def get_data():
    with data_lock:
        return jsonify(data_store)

@app.route("/api/data", methods=["POST"])
def post_data():
    req = request.json

    cmd = f"C,{req['controlType']},{req['valveLevel']}\n"
    
    if ser and ser.is_open:
        ser.write(cmd.encode())
        print(f"Inviato a Seriale: {cmd}")
        return jsonify({"status": "ok"})
    
    return jsonify({"status": "error", "message": "Seriale non disponibile"}), 500

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python main.py <port> <baudrate>")
        sys.exit(1)

    L1, L2, T1, T2 = 40.0, 70.0, 5.0, 10.0
    
    threading.Thread(target=mqtt_worker, daemon=True).start()
    threading.Thread(target=serial_worker, args=(sys.argv[1], int(sys.argv[2])), daemon=True).start()
    
    app.run(host="0.0.0.0", port=8080, debug=False, use_reloader=False)
