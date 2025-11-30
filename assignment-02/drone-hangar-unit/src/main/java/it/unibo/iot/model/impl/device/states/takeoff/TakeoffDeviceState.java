package it.unibo.iot.model.impl.device.states.takeoff;

import it.unibo.iot.common.api.Messages;
import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.impl.device.states.AbstractDeviceState;
import it.unibo.iot.model.impl.device.states.operating.OperatingDeviceState;

/**
 * Represents the device state during takeoff.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class TakeoffDeviceState extends AbstractDeviceState {

    /**
     * Handles an incoming message while the device is taking off.
     * Typical transition: "operating" -> OperatingDeviceState.
     *
     * @param device the device instance receiving the message
     * @param msg    the received message; must not be null
     */
    @Override
    public void handle(final Device device, final String msg) {
        super.handle(device, msg);
        switch (Messages.fromString(msg)) {
            case OUTSIDE -> device.changeState(new OperatingDeviceState());
            default -> {
            }
        }
    }

    /**
     * Returns the textual representation of this state.
     *
     * @return "TAKEOFF STATE"
     */
    @Override
    public String toString() {
        return "TAKEOFF STATE\n" + super.toString();
    }

}
