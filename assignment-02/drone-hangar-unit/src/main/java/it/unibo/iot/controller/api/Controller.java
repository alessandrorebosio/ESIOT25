package it.unibo.iot.controller.api;

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
     * Checks if the controller is currently running.
     *
     * @return true if the controller is running, false otherwise
     */
    boolean isRunning();

}
