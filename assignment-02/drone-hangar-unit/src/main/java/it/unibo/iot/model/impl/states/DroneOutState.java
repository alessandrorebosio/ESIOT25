package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.DroneModel;
import it.unibo.iot.model.api.Event;

/**
 * Drone state representing the drone outside the hangar.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class DroneOutState extends AbstractDroneState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void onEnter(final DroneModel model) {
        model.sendCommand("DRONE OUT");
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
