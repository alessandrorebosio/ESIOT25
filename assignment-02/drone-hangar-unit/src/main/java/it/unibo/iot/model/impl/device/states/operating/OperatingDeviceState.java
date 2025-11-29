package it.unibo.iot.model.impl.device.states.operating;

import it.unibo.iot.common.api.Messages;
import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.impl.device.states.AbstractDeviceState;
import it.unibo.iot.model.impl.device.states.landing.LandingDeviceState;

/**
 * Represents the device state when it is operating.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class OperatingDeviceState extends AbstractDeviceState {

    /**
     * Handles an incoming message while the device is operating.
     * Typical transition: "landing" -> LandingDeviceState.
     *
     * @param device the device instance receiving the message
     * @param msg    the received message; must not be null
     */
    @Override
    public void handle(final Device device, final String msg) {
        super.handle(device, msg);
        switch (Messages.fromString(msg)) {
            case LANDING -> device.changeState(new LandingDeviceState());
            default -> {
            }
        }
    }

    /**
     * Returns the textual representation of this state.
     *
     * @return "OPERATING STATE"
     */
    @Override
    public String toString() {
        return "OPERATING STATE";
    }

}
