package it.unibo.iot.controller.api;

import java.util.List;

/**
 * Interface representing a controller that manages the application state.
 * Provides methods for application lifecycle management, serial communication,
 * and drone control operations.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public interface Controller {

    /**
     * Starts the controller and begins its operation.
     */
    void start();

    /**
     * Stops the controller and ends its operation.
     */
    void stop();

    /**
     * Perform a single update cycle of the controller.
     */
    void update();

    /**
     * Checks if the controller is currently running.
     *
     * @return true if the controller is running, false otherwise
     */
    boolean isRunning();

    /**
     * Retrieves a list of available serial ports on the system.
     *
     * @return a list of available serial port names
     */
    List<String> getAvailablePort();

    /**
     * Checks if a serial connection is currently established.
     *
     * @return true if connected to a serial device, false otherwise
     */
    boolean isConnected();

    /**
     * Establishes a connection to the specified serial port.
     *
     * @param portName the name of the serial port to connect to
     * @param baudRate the baud rate for the serial communication
     * @return true if connection was successful, false otherwise
     */
    boolean connect(String portName, int baudRate);

    /**
     * Disconnects from the current serial port.
     *
     * @return true if disconnection was successful, false otherwise
     */
    boolean disconnect();

    /**
     * Sends a message through the serial connection.
     *
     * @param msg the message to send
     */
    void sendMsg(String msg);

}
