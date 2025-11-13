package it.unibo.iot.core.api;

/**
 * Interface representing the main engine of the application.
 * Responsible for running and stopping the application's main loop.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public interface Engine {

    /**
     * Starts the engine and begins the main application loop.
     */
    void run();

    /**
     * Stops the engine and terminates the application.
     */
    void stop();

}
