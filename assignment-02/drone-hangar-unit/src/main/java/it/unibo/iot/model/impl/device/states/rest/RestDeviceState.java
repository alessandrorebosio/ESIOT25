package it.unibo.iot.model.impl.device.states.rest;

import it.unibo.iot.model.impl.device.states.AbstractDeviceState;

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
    public String toString() {
        return "REST";
    }

}
