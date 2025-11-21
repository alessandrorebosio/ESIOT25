package it.unibo.iot.model.impl.states.prealarm;

import it.unibo.iot.common.SystemState;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.impl.states.AbstractAppState;

public class PreAlarmState extends AbstractAppState {

    @Override
    public void update(Model t, float deltaTime) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'update'");
    }

    @Override
    public SystemState getStateType() {
        return SystemState.PREALARM;
    }

}
