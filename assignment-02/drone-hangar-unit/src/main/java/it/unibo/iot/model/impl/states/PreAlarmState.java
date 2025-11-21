package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.DroneModel;
import it.unibo.iot.model.api.Event;

/**
 * State representing the pre-alarm condition of the system.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class PreAlarmState extends AbstractDroneState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void onEnter(final DroneModel model) {
        model.sendCommand("PREALARM");
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final DroneModel model, final Event event) {
        switch (event) {
            case TEMP_NORMAL -> model.setState(model.getPreviousState());
            default -> { }
        }
    }
}
