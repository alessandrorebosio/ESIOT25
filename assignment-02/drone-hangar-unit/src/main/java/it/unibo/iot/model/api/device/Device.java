package it.unibo.iot.model.api.device;

import it.unibo.iot.model.api.device.states.DeviceState;

/**
 * Represents a generic IoT device that can hold and change its state.
 * 
 * @author Grazia Bochdanovtis de Kavna
 */
public interface Device {

    /**
     * Returns the current state of the device.
     *
     * @return the current {@link DeviceState}.
     */
    DeviceState getDeviceState();

    /**
     * Changes the current state of the device.
     *
     * @param newState the new {@link DeviceState} to set.
     */
    void changeState(DeviceState newState);
}
