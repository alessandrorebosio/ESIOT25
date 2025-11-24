package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.states.SystemState;

/**
 * Base class for all system states.
 * Provides default empty implementations of the {@link SystemState}
 * lifecycle methods.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public abstract class AbstractSystemState implements SystemState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void onEnter(final Model t) {
        // Default: do nothing
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void onExit(final Model t) {
        // Default: do nothing
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void update(final Model t) {
        // Default: do nothing
    }

    /**
     * Returns the name of this state.
     *
     * @return the state name as a string.
     */
    @Override
    public abstract String toString();
}
