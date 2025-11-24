package it.unibo.iot.model.impl.device;

import java.util.Objects;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.DeviceState;
import it.unibo.iot.model.impl.device.states.unkwown.UnknownDeviceState;

/**
 * Represents a drone device capable of changing and tracking its state.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class Drone implements Device {

    private DeviceState state;

    /**
     * Creates a new drone with an initial {@link UnknownDeviceState}.
     */
    public Drone() {
        this(new UnknownDeviceState());
    }

    /**
     * Creates a new drone with the specified initial state.
     *
     * @param state the initial {@link DeviceState}; must not be {@code null}.
     */
    public Drone(final DeviceState state) {
        this.state = Objects.requireNonNull(state, "The device initial state cannot be null.");
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public DeviceState getDeviceState() {
        return this.state;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void changeState(final DeviceState newState) {
        if (this.state != null) {
            this.state.onExit(this);
        }
        this.state = newState;
        this.state.onEnter(this);
    }
}
