package it.unibo.iot.model.impl.states.alarm;

import it.unibo.iot.model.impl.states.AbstractAppState;

/**
 * Critical alarm state.
 * Only RESET is allowed and returns the system to DroneInsideState.
 * All other events are ignored.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class AlarmState extends AbstractAppState {

    @Override
    public void handle() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'handle'");
    }

}
