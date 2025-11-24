package it.unibo.iot.model.impl.device.states;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.DeviceState;

/**
 * Base class for all device states.
 * Provides default empty implementations for the {@link DeviceState} lifecycle methods.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public abstract class AbstractDeviceState implements DeviceState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void onEnter(final Device t) {
        // Default: do nothing
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void onExit(final Device t) {
        // Default: do nothing
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void update(final Device t) {
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
