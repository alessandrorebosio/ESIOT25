package it.unibo.iot.model.impl.device;

import java.util.Objects;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.DeviceState;
import it.unibo.iot.model.impl.device.states.unkwown.UnknownDeviceState;

public class Drone implements Device {

    private DeviceState state;

    public Drone() {
        this(new UnknownDeviceState());
    }

    public Drone(final DeviceState state) {
        Objects.requireNonNull(state, "The device initial state cannot be null.");
        this.changeState(state);
    }

    @Override
    public DeviceState getDeviceState() {
        return this.state;
    }

    @Override
    public void changeState(final DeviceState newState) {
        if (this.state != null) {
            this.state.onExit(this);
        }
        this.state = newState;
        this.state.onEnter(this);
    }

}
