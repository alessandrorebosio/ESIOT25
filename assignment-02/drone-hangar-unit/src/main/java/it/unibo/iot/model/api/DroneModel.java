package it.unibo.iot.model.api;

import it.unibo.iot.model.api.states.DroneState;

/**
 * Extension of the application model that exposes operations
 * required by the drone finite-state machine.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public interface DroneModel {

    /**
     * Sets the current state of the finite-state machine.
     *
     * @param newState the new drone state
     */
    void setState(DroneState newState);

    /**
     * @return the name of the current state of the FSM
     */
    String getCurrentState();

    /**
     * @return the name of the last state of the FSM
     */
    DroneState getPreviousState();

    /**
     * Handles an incoming domain event and delegates it to
     * the current state of the FSM.
     *
     * @param event the event to process
     */
    void handle(Event event);

    /**
     * Sends a command to the underlying system (e.g., Arduino/hardware layer).
     *
     * @param message the command string to send
     */
    void sendCommand(String message);
}
