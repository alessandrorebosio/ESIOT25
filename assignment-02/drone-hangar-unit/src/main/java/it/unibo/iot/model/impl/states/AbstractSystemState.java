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

    private float sysTemp;

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
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final Model model, final String msg) {
        Objects.requireNonNull(model, "The model cannot be null.");
        Objects.requireNonNull(msg, "The msg cannot be null.");

        if (msg.contains("T:")) {
            final int idx = msg.indexOf("T:");
            if (idx >= 0) {
                final String after = msg.substring(idx + 2).trim();
                if (!after.isEmpty()) {
                    try {
                        final String numberToken = after.split("\\s+")[0];
                        this.sysTemp = Float.parseFloat(numberToken);
                    } catch (final NumberFormatException e) {
                        // Invalid temperature value, set to -1
                        this.sysTemp = -1f;
                    }
                }
            }
        }
    }

    /**
     * Returns the name of this state.
     *
     * @return the state name as a string.
     */
    @Override
    public String toString() {
        return "TEMPERATURE: " + this.sysTemp + "°C";
    }

}
