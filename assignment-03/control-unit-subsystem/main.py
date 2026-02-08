import time
import threading
from flask import Flask, request, jsonify
from flask_cors import CORS
from serialConn.serialConn import SerialDevice
from mqtt.mqtt import MQTTClient

L1, L2, T1, T2 = 40.0, 70.0, 5.0, 10.0
N = 20

app = Flask(__name__)
CORS(app)
cus = None

class ControlUnit:
    def __init__(self):
        self.wcs = SerialDevice("COM3", 9600, timeout=0.1)
        self.tms = MQTTClient(broker="broker.mqtt-dashboard.com", topic="RiverMonitoring/esp32/backend")
        
        self.water_level = 0.0
        self.last_tms_time = time.time()
        self.l1_start_time = None
        self.override_active = False
        self.current_valve_level = 0
        
        self.history = [] 

    def on_tms_message(self, topic, payload):
        try:
            valore = payload.get("value") or payload.get("raw", "0")
            self.water_level = float(str(valore).strip())
            self.last_tms_time = time.time()
            
            data_point = {
                "time": time.strftime("%Y-%m-%dT%H:%M:%S"),
                "waterLevel": self.water_level,
                "valveLevel": self.current_valve_level,
                "controlType": "DATA",
                "state": self.get_system_state()
            }
            self.history.insert(0, data_point)
            if len(self.history) > N:
                self.history.pop()
                
        except Exception as e:
            print(f"[ERROR] Failed to process TMS message: {e}")

    def get_system_state(self):
        if (time.time() - self.last_tms_time) > T2: return "UNCONNECTED"
        if self.override_active: return "MANUAL"
        return "AUTOMATIC"

    def run_logic(self):
        self.wcs.open()
        self.tms.set_message_handler(self.on_tms_message)
        self.tms.connect()
        
        while True:
            now = time.time()
            if not self.override_active:
                if (now - self.last_tms_time) < T2:
                    if self.water_level > L2:
                        angle = 90
                        self.l1_start_time = None
                    elif self.water_level > L1:
                        if self.l1_start_time is None: self.l1_start_time = now
                        angle = 45 if (now - self.l1_start_time) > T1 else 0
                    else:
                        angle = 0
                        self.l1_start_time = None
                    
                    self.current_valve_level = int((angle * 100) / 90)
                    self.wcs.send(str(angle))
            time.sleep(1)

@app.route('/api/data', methods=['GET'])
def get_data():
    return jsonify(cus.history if cus.history else [{
        "time": time.strftime("%Y-%m-%dT%H:%M:%S"),
        "waterLevel": cus.water_level,
        "valveLevel": cus.current_valve_level,
        "controlType": "DATA",
        "state": cus.get_system_state()
    }])

@app.route('/api/data', methods=['POST'])
def post_data():
    data = request.json
    control_type = data.get("controlType")
    
    if control_type == "SWITCH_TO_AUTO":
        cus.override_active = False
        
    elif control_type == "SET":
        cus.override_active = True
        valve_level = int(data.get("valveLevel", 0))
        angle = int((valve_level * 90) / 100)
        cus.current_valve_level = valve_level
        cus.wcs.send(str(angle))
        
    return jsonify({"status": "ok"})

if __name__ == "__main__":
    cus = ControlUnit()
    threading.Thread(target=cus.run_logic, daemon=True).start()
    app.run(port=8080, debug=False, use_reloader=False)