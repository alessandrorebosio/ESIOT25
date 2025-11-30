package it.unibo.iot.controller.api;

import java.util.List;
import java.util.Optional;

import it.unibo.iot.model.api.device.states.DeviceState;
import it.unibo.iot.model.api.states.SystemState;

/**
 * Interface representing a controller that manages the application state.
 * Provides methods for application lifecycle management, serial communication,
 * drone control operations, and state retrieval.
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
     * Handles incoming messages from the serial monitor.
     */
    void handle();

    /**
     * Perform a single update cycle of the controller.
     */
    void update();

    /**
     * Sends a message through the serial connection.
     *
     * @param msg the message to send
     */
    void sendMsg(String msg);

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
     * Checks if the controller is currently running.
     *
     * @return true if the controller is running, false otherwise
     */
    boolean isRunning();

    /**
     * Checks if a serial connection is currently established.
     *
     * @return true if connected to a serial device, false otherwise
     */
    boolean isConnected();

    /**
     * Retrieves a list of available serial ports on the system.
     *
     * @return a list of available serial port names
     */
    List<String> getAvailablePort();

    /**
     * Retrieves the current state of the device (drone).
     *
     * @return the current device state
     */
    DeviceState getDeviceState();

    /**
     * Retrieves the current state of the overall system.
     *
     * @return the current system state
     */
    SystemState getSystemState();

    /**
     * Returns the current drone distance.
     * 
     * @return the drone distance.
     */
    float getDroneDistance();

    /**
     * Returns the current system temperature.
     * 
     * @return the system temperature.
     */
    float getSystemTemperature();

    /**
     * Retrieves the most recent message from the system, if available.
     *
     * @return an Optional containing the most recent message, or empty if no
     *         message is available
     */
    Optional<String> message();

}
