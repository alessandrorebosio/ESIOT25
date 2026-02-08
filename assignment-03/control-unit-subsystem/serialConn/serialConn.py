import time
from typing import Optional, TYPE_CHECKING

if TYPE_CHECKING:
    from serial import Serial 

try:
    import serial
except Exception:
    serial = None


class SerialDevice:
    """
    Simple serial communication wrapper using pyserial.
    """
    
    def __init__(self, port: str, baud: int = 9600, timeout: float = 1.0):
        """
        Create a serial device connection.
        
        Args:
            port: Serial port name (e.g., "COM3" on Windows, "/dev/ttyUSB0" on Linux)
            baud: Communication speed (default: 9600)
            timeout: Read timeout in seconds (default: 1.0)
        """
        self.port = port
        self.baud = baud
        self.timeout = timeout
        self._ser: Optional["Serial"] = None

    def open(self):
        """
        Open the serial connection.
        
        Raises:
            RuntimeError: If pyserial is not installed or connection fails
        """
        if serial is None:
            raise RuntimeError("pyserial not installed")
        self._ser = serial.Serial(self.port, self.baud, timeout=self.timeout)
        time.sleep(0.1)

    def send(self, line: str):
        """
        Send a string through the serial port.
        
        Args:
            line: String to send
            
        Raises:
            RuntimeError: If serial port is not open
        """
        if not self._ser or not self._ser.is_open:
            raise RuntimeError("serial port not open")
        data = (line.rstrip("\n") + "\n").encode()
        self._ser.write(data)

    def receive(self) -> Optional[str]:
        """
        Read a line from the serial port.
        """
        if not self._ser or not self._ser.is_open:
            return None
        try:
            raw = self._ser.readline()
            if not raw:
                return None
            return raw.decode(errors="ignore").rstrip("\r\n")
        except Exception:
            return None

    def close(self):
        """
        Close the serial connection safely.
        """
        try:
            if self._ser and self._ser.is_open:
                self._ser.close()
        except Exception:
            pass
