package it.unibo.iot.model.impl.states.prealarm;

import it.unibo.iot.common.SystemState;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.impl.states.AbstractAppState;

/**
 * Represents the PREALARM application state. Behaviour for this transitional
 * state should be implemented in {@link #update(Model, float)}.
 *
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class PreAlarmState extends AbstractAppState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void update(final Model t, final float deltaTime) {
        // TODO: implement pre-alarm update behavior
        throw new UnsupportedOperationException("Unimplemented method 'update'");
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public SystemState getStateType() {
        return SystemState.PREALARM;
    }

}
