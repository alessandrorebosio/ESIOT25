import json
import threading
from typing import Callable, Optional

import paho.mqtt.client as mqtt


class MQTTClient:
    """
    Simple MQTT client for sending and receiving messages.
    
    Handles connection to an MQTT broker, subscribing to topics,
    and processing incoming messages with a callback function.
    """
    
    def __init__(
        self, broker: str = "localhost", port: int = 1883, topic: str = "tms/commands"
    ):
        """
        Create an MQTT client.
        
        Args:
            broker: MQTT broker address (default: "localhost")
            port: MQTT broker port (default: 1883)
            topic: Topic to subscribe to (default: "tms/commands")
        """
        self.broker = broker
        self.port = port
        self.topic = topic
        self._client = mqtt.Client()
        self._on_message: Optional[Callable[[str, dict], None]] = None

        self._client.on_connect = self._on_connect
        self._client.on_message = self._on_message_internal

    def _on_connect(self, client, userdata, flags, rc):
        """Called when connected to broker. Subscribes to the topic."""
        if rc == 0:
            client.subscribe(self.topic)

    def _on_message_internal(self, client, userdata, msg):
        """
        Called when a message is received.
        Converts message to JSON and calls user's handler in a separate thread.
        """
        try:
            content = json.loads(msg.payload.decode())
            if not isinstance(content, dict):
                payload = {"value": content, "raw": str(content)}
            else:
                payload = content
        except Exception:
            payload = {"raw": msg.payload.decode(errors="ignore")}
        if self._on_message:
            threading.Thread(
                target=self._on_message, args=(msg.topic, payload), daemon=True
            ).start()

    def set_message_handler(self, fn: Callable[[str, dict], None]):
        """
        Set the function to call when a message is received.
        
        Args:
            fn: Function that takes (topic: str, payload: dict) as arguments
        """
        self._on_message = fn

    def connect(self):
        """
        Connect to the MQTT broker and start listening for messages.
        """
        self._client.connect(self.broker, self.port)
        self._client.loop_start()

    def publish(self, topic: str, payload: dict):
        """
        Send a message to a topic.
        
        Args:
            topic: Topic to publish to
            payload: Dictionary to send (will be converted to JSON)
        """
        self._client.publish(topic, json.dumps(payload))

    def stop(self):
        """
        Stop the MQTT client and disconnect from broker.
        """
        try:
            self._client.loop_stop()
            self._client.disconnect()
        except Exception:
            pass
