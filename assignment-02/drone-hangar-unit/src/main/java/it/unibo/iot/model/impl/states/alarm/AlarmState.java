package it.unibo.iot.model.impl.states.alarm;

import it.unibo.iot.common.SystemState;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.impl.states.AbstractAppState;

/**
 * Represents the ALARM application state. In this state the application
 * should behave according to alarm requirements.
 * 
 * <p>
 * Concrete behaviour for {@link #update(Model, float)} is left unimplemented
 * and should be provided when needed.
 *
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AlarmState extends AbstractAppState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void update(final Model t, final float deltaTime) {
        // TODO: implement alarm update behavior
        throw new UnsupportedOperationException("Unimplemented method 'update'");
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public SystemState getStateType() {
        return SystemState.ALARM;
    }

}
