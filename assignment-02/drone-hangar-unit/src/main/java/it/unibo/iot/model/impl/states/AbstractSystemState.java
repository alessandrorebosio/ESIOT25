package it.unibo.iot.model.impl.states;

import java.util.Objects;

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
    public void onEnter(final Model model) {
        // Default: do nothing
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void onExit(final Model model) {
        // Default: do nothing
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void update(final Model model) {
        model.getDevice().update();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final Model model, final String msg) {
        Objects.requireNonNull(model, "The model cannot be null.");
        Objects.requireNonNull(msg, "The msg cannot be null.");
        model.getDevice().handle(msg);
    }

    /**
     * Returns the name of this state.
     *
     * @return the state name as a string.
     */
    @Override
    public abstract String toString();

}
