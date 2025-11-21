package it.unibo.iot.model.impl.drone;

import java.util.Objects;
import java.util.Optional;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.DeviceState;
import it.unibo.iot.model.api.device.states.EnumState;
import it.unibo.iot.model.impl.drone.states.rest.RestState;

public class Drone implements Device {

    private DeviceState state;

    public Drone() {
        this(new RestState());
    }

    public Drone(final DeviceState state) {
        this.changeState(state);
    }

    @Override
    public void changeState(final DeviceState newState) {
        if (this.state != null) {
            this.state.onExit(this);
        }
        this.state = Objects.requireNonNull(newState, "The newState cannot be null.");
        this.state.onEnter(this);
    }

    @Override
    public void handleState(final Device device, final EnumState event) {
        Optional.ofNullable(state).ifPresent(s -> s.handle(this, event));
    }

    @Override
    public EnumState getState() {
        return this.state.getState();
    }

}
