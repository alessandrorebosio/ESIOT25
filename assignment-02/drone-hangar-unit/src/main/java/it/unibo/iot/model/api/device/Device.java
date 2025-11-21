package it.unibo.iot.model.api.device;

import it.unibo.iot.model.api.device.states.DeviceState;
import it.unibo.iot.model.api.device.states.EnumState;

public interface Device {

    void changeState(DeviceState newState);

    void handleState(Device device, EnumState event);

    EnumState getState();

}
