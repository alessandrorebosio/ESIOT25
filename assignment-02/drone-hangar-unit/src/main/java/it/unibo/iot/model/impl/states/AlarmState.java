package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.DroneModel;
import it.unibo.iot.model.api.Event;

/**
 * Critical alarm state.
 * Only RESET is allowed and returns the system to DroneInsideState.
 * All other events are ignored.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class AlarmState extends AbstractDroneState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void onEnter(final DroneModel model) {
        model.sendCommand("ALARM");
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
