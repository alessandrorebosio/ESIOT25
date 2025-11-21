package it.unibo.iot.model.api;

import it.unibo.iot.model.api.states.AppState;

/**
 * Extension of the application model that exposes operations
 * required by the drone finite-state machine.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public interface HangarModel {

    /**
     * Sets the current state of the finite-state machine.
     *
     * @param newState the new drone state
     */
    void changeState(AppState newState);

    /**
     * @return the name of the current state of the FSM
     */
    String getAppState();

}
