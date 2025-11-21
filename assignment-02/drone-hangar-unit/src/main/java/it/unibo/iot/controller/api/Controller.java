package it.unibo.iot.controller.api;

import it.unibo.iot.model.api.Event;

/**
 * Interface representing a controller that manages the application state.
 * Provides methods to check if the controller is running, start it, and stop
 * it.
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
     * Handles an incoming event.
     * 
     * @param event the incoming event
     */
    void onEvent(Event event);
}
