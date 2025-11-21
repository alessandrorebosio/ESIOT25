package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.DroneModel;
import it.unibo.iot.model.api.Event;

/**
 * Drone state representing the takeoff phase.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class DroneTakeoffState extends AbstractDroneState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void onEnter(final DroneModel model) {
        model.sendCommand("TAKEOFF");
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final DroneModel model, final Event event) {
        switch (event) {
            case LANDING -> model.setState(new DroneLandingState());
            default -> { }
        }
    }
}
