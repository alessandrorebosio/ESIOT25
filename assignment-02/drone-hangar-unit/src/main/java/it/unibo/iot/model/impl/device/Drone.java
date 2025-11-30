package it.unibo.iot.model.impl.device;

import java.util.Objects;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.DeviceState;
import it.unibo.iot.model.impl.device.states.unknown.UnknownDeviceState;

/**
 * Represents a drone device capable of changing and tracking its state.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class Drone implements Device {

    private DeviceState state;
    private float drnDistance;

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
        this.state = Objects.requireNonNull(state, "The initial device state cannot be null.");
    }

    /**
     * Change the current device state invoking lifecycle callbacks.
     *
     * @param newState the new device state; must not be {@code null}
     */
    @Override
    public void changeState(final DeviceState newState) {
        if (this.state != null) {
            this.state.onExit(this);
        }
        this.state = newState;
        this.state.onEnter(this);
    }

    /**
     * Invokes the update lifecycle on the underlying state.
     */
    @Override
    public void update() {
        this.state.update(this);
    }

    /**
     * Forwards an input message to the current device state handler.
     *
     * @param msg the message to handle; must not be null
     */
    @Override
    public void handle(final String msg) {
        this.state.handle(this, msg);
    }

    /**
     * Returns the current DeviceState instance.
     *
     * @return the current device state
     */
    @Override
    public DeviceState getDeviceState() {
        return this.state;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public float getDroneDistance() {
        return this.drnDistance;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void setDroneDistance(final float distance) {
        this.drnDistance = distance;
    }

}
