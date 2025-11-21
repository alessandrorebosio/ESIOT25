package it.unibo.iot.model.api.device.states;

import it.unibo.iot.common.State;
import it.unibo.iot.model.api.device.Device;

public interface DeviceState extends State<Device> {

    void handle(Device device, EnumState event);

    EnumState getState();

}
