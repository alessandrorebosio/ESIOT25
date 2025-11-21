package it.unibo.iot.model.api;

import it.unibo.iot.common.SystemState;
import it.unibo.iot.model.api.states.AppState;

/**
 * Interface representing the application model.
 * Defines methods to manage the running state of the application.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public interface Model {

    /**
     * Starts the model and sets it to running state.
     */
    void start();

    /**
     * Stops the model and sets it to not running state.
     */
    void stop();

    /**
     * Checks if the model is currently running.
     *
     * @return true if the model is running, false otherwise
     */
    boolean isRunning();

    void changeState(AppState newState);

    void handle(SystemState state);

    SystemState getState();

}
