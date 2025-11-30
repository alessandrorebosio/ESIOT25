package it.unibo.iot.model.impl.device.states.unknown;

import it.unibo.iot.common.api.Messages;
import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.impl.device.states.AbstractDeviceState;
import it.unibo.iot.model.impl.device.states.landing.LandingDeviceState;
import it.unibo.iot.model.impl.device.states.operating.OperatingDeviceState;
import it.unibo.iot.model.impl.device.states.rest.RestDeviceState;
import it.unibo.iot.model.impl.device.states.takeoff.TakeoffDeviceState;

/**
 * Represents an unknown or undefined device state.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class UnknownDeviceState extends AbstractDeviceState {

    /**
     * Handles an incoming message while the device state is unknown.
     * Maps recognized keywords to concrete device states.
     *
     * @param device the device instance receiving the message
     * @param msg    the received message; must not be null
     */
    @Override
    public void handle(final Device device, final String msg) {
        super.handle(device, msg);
        switch (Messages.fromString(msg)) {
            case INSIDE -> device.changeState(new RestDeviceState());
            case TAKEOFF -> device.changeState(new TakeoffDeviceState());
            case OUTSIDE -> device.changeState(new OperatingDeviceState());
            case LANDING -> device.changeState(new LandingDeviceState());
            default -> {
            }
        }
    }

    /**
     * Returns the textual representation of this state.
     *
     * @return "UNKNOWN STATE"
     */
    @Override
    public String toString() {
        return "UNKNOWN STATE\n" + super.toString();
    }

}
