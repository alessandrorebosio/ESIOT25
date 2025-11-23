package it.unibo.iot.model.api;

import java.util.Optional;

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

    void addMsg(String msg);

    Optional<String> take();

    /**
     * Starts the model and sets it to running state.
     */
    void start();

    /**
     * Stops the model and sets it to not running state.
     */
    void stop();

    void changeState(SystemState newState);

    /**
     * Checks if the model is currently running.
     *
     * @return true if the model is running, false otherwise
     */
    boolean isRunning();

    DeviceState getDeviceState();

    SystemState getAppState();

}
