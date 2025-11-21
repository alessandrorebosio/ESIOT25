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

    /**
     * Requests the model to change its current application state.
     *
     * @param newState the new {@link AppState} to switch to; must not be null
     */
    void changeState(AppState newState);

    /**
     * Informs the model of a new {@link SystemState} event to handle.
     * Implementations should translate the system-level state into an
     * application state transition when appropriate.
     *
     * @param state the incoming system state to handle; must not be null
     */
    void handle(SystemState state);

    /**
     * Returns the current {@link SystemState} represented by the model.
     *
     * @return the current SystemState
     */
    SystemState getState();

}
