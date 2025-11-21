package it.unibo.iot.model.impl.drone.states;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.DeviceState;

public abstract class AbstractDroneState implements DeviceState {

    @Override
    public void onEnter(final Device t) {
    }

    @Override
    public void onExit(final Device t) {
    }

    @Override
    public void update(final Device t, final float deltaTime) {
    }

}
