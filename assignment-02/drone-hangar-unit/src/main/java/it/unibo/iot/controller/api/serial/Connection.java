package it.unibo.iot.controller.api.serial;

import java.util.Arrays;
import java.util.Optional;

import com.fazecast.jSerialComm.SerialPort;

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
     * Establishes a connection to the specified serial port.
     *
     * @return true if connection was successful, false otherwise
     */
    boolean connect();

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
     * Checks whether the serial port associated with this connection is currently
     * available
     * for opening and use.
     *
     * @return {@code true} if the port appears available for use; {@code false} if
     *         the port
     *         is occupied, inaccessible, or otherwise not available.
     */
    boolean isPortAvailable();

    /**
     * Checks if the specified serial port is available on the system.
     *
     * @param portName the port name to check
     * @return true if the port is available, false otherwise
     */
    static boolean isPortAvailable(final String portName) {
        return Arrays.stream(SerialPort.getCommPorts())
                .map(SerialPort::getSystemPortPath)
                .anyMatch(name -> name.contains(portName));
    }

}
