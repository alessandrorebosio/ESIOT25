package it.unibo.iot.controller.api.serial;

import java.util.List;
import java.util.Optional;

/**
 * Interface for managing serial port connections.
 * Provides methods for connection establishment, data transmission, and port
 * availability checks.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public interface Connection {

    /**
     * Establishes a connection to the specified serial port using the given baud
     * rate.
     *
     * @param portName the system port path or name (for example "/dev/ttyUSB0" or
     *                 "COM3")
     * @param baudRate the serial communication baud rate (for example 9600 or
     *                 115200)
     * @return true if the connection was successful, false otherwise
     */
    boolean connect(String portName, int baudRate);

    /**
     * Closes the serial connection and releases resources.
     *
     * @return true if disconnection was successful, false otherwise
     */
    boolean disconnect();

    /**
     * Checks if the serial connection is currently open.
     *
     * @return true if the connection is open, false otherwise
     */
    boolean isConnected();

    /**
     * Sends a message through the serial connection.
     *
     * @param message the message to send
     * @return true if the message was sent successfully, false otherwise
     */
    boolean send(String message);

    /**
     * Retrieves the next available received message.
     *
     * @return the received message, or null if no messages are available
     */
    Optional<String> receive();

    /**
     * Returns a list of system paths for the serial ports currently available on
     * the host.
     *
     * @return a List of system port path strings for the available serial ports;
     *         empty if none are found
     */
    List<String> getAvailablePort();

}
