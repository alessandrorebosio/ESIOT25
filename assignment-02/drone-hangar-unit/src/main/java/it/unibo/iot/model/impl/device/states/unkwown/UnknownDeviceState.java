package it.unibo.iot.model.impl.device.states.unkwown;

import it.unibo.iot.model.impl.device.states.AbstractDeviceState;

/**
 * Represents an unknown or undefined device state.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class UnknownDeviceState extends AbstractDeviceState {

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return "UNKNOWN";
    }

}
