package it.unibo.iot.model.impl.device.states.rest;

import it.unibo.iot.common.api.Messages;
import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.impl.device.states.AbstractDeviceState;
import it.unibo.iot.model.impl.device.states.takeoff.TakeoffDeviceState;

/**
 * Represents the device state when it is at rest.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class RestDeviceState extends AbstractDeviceState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final Device device, final String msg) {
        super.handle(device, msg);
        switch (Messages.fromString(msg)) {
            case TAKEOFF -> device.changeState(new TakeoffDeviceState());
            default -> {
            }
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return "REST STATE";
    }

}
