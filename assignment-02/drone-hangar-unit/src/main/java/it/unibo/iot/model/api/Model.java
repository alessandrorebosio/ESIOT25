package it.unibo.iot.model.api;

import java.util.Optional;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.DeviceState;
import it.unibo.iot.model.api.states.SystemState;

/**
 * Interface representing the application model.
 * Defines methods to manage the running state of the application.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public interface Model {

    /**
     * Adds a message to the model’s internal message queue.
     *
     * @param msg the message to add; must not be {@code null}.
     */
    void addMsg(String msg);

    /**
     * Retrieves and removes the next available message from the queue.
     *
     * @return an {@link Optional} containing the next message,
     *         or an empty {@code Optional} if no messages are available.
     */
    Optional<String> take();

    /**
     * Starts the model and sets its running state to {@code true}.
     */
    void start();

    /**
     * Stops the model and sets its running state to {@code false}.
     */
    void stop();

    /**
     * Handle an incoming message destined for this model.
     * 
     * @param msg the message to handle.
     */
    void handle(String msg);

    /**
     * Performs a model update cycle.
     */
    void update();

    /**
     * Changes the current {@link SystemState} of the model.
     *
     * @param newState the new system state; must not be {@code null}.
     */
    void changeState(SystemState newState);

    /**
     * Checks whether the model is currently running.
     *
     * @return {@code true} if the model is running, {@code false} otherwise.
     */
    boolean isRunning();

    /**
     * Retrieves the device associated with this model.
     * 
     * @return the device
     */
    Device getDevice();

    /**
     * Returns the current {@link DeviceState} of the associated device.
     *
     * @return the device state.
     */
    DeviceState getDeviceState();

    /**
     * Returns the current {@link SystemState} of the application.
     *
     * @return the application (system) state.
     */
    SystemState getAppState();

}
