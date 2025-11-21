package it.unibo.iot.model.api.states;

import it.unibo.iot.model.api.DroneModel;
import it.unibo.iot.model.api.Event;

/**
 * Represents a concrete state in the drone finite-state machine.
 * Extends the generic state interface by adding handling of domain events.
 * 
 * @author Grazia Bochdanovit de Kavna
 */
public interface DroneState extends State<DroneModel> {

    /**
     * Called when an event arrives before state transition logic.
     * 
     * @param event the incoming event
     */
    void onEvent(Event event);

    /**
     * Processes a domain event and performs eventual state transitions.
     *
     * @param model the drone model acting as FSM context
     * @param event the incoming event
     */
    void handle(DroneModel model, Event event);
}
