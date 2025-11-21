package it.unibo.iot.model.api;

/**
 * Interface representing the application model.
 * Defines methods to manage the running state of the application.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public interface Model extends DroneModel {

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
     * Registers a listener that will receive outgoing command strings.
     *
     * @param cmd a consumer receiving command messages
     */
    void setCommandSender(CommandSender cmd);
}
