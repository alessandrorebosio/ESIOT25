package it.unibo.iot.model.impl.device.states;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.DeviceState;

public abstract class AbstractDeviceState implements DeviceState {

    @Override
    public void onEnter(final Device t) {
    }

    @Override
    public void onExit(final Device t) {
    }

    @Override
    public void update(final Device t) {

    }

    @Override
    public abstract String toString();

}
