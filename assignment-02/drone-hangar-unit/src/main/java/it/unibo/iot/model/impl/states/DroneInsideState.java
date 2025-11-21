package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.DroneModel;
import it.unibo.iot.model.api.Event;

/**
 * Drone state representing the drone inside the hangar.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class DroneInsideState extends AbstractDroneState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void onEnter(final DroneModel model) {
        model.sendCommand("INSIDE");
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final DroneModel model, final Event event) {
        switch (event) {
            case TAKEOFF -> model.setState(new DroneTakeoffState());
            default -> { }
        }
    }
}
