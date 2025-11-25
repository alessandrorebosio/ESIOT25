package it.unibo.iot.model.api.device;

import it.unibo.iot.model.api.device.states.DeviceState;

/**
 * Represents a generic IoT device that can hold and change its state.
 * 
 * @author Grazia Bochdanovtis de Kavna
 */
public interface Device {

    /**
     * Changes the current state of the device.
     *
     * @param newState the new {@link DeviceState} to set.
     */
    void changeState(DeviceState newState);

    /**
     * Refreshes the device's internal state.
     */
    void update();

    /**
     * Handles an incoming message for device processing.
     * 
     * @param msg the message to handle.
     */
    void handle(String msg);

    /**
     * Returns the current state of the device.
     *
     * @return the current {@link DeviceState}.
     */
    DeviceState getDeviceState();

}
