package it.unibo.iot.model.impl.states.normal;

import it.unibo.iot.common.SystemState;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.impl.states.AbstractAppState;

/**
 * Represents the NORMAL application state. Default behaviour for the normal
 * state should be implemented in {@link #update(Model, float)}.
 *
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class NormalState extends AbstractAppState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void update(final Model t, final float deltaTime) {
        // TODO: implement normal state update behavior
        throw new UnsupportedOperationException("Unimplemented method 'update'");
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public SystemState getStateType() {
        return SystemState.NORMAL;
    }

}
