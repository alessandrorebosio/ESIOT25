package it.unibo.iot.model.api.device;

import it.unibo.iot.model.api.device.states.DeviceState;

public interface Device {

    DeviceState getDeviceState();

    void changeState(DeviceState newState);

}
