package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.DroneModel;
import it.unibo.iot.model.api.Event;

/**
 * Drone state representing the landing phase.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class DroneLandingState extends AbstractDroneState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void onEnter(final DroneModel model) {
        model.sendCommand("LANDING");
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final DroneModel model, final Event event) {
        switch (event) {
            case RESET -> model.setState(new DroneInsideState());
            default -> { }
        }
    }
}
