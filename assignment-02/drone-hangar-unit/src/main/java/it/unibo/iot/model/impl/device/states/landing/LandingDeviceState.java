package it.unibo.iot.model.impl.device.states.landing;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.impl.device.states.AbstractDeviceState;
import it.unibo.iot.model.impl.device.states.rest.RestDeviceState;

/**
 * Represents the device state during landing.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class LandingDeviceState extends AbstractDeviceState {

    /**
     * Handles an incoming message while the device is in the landing state.
     * Expected messages may trigger a state transition (e.g. "rest").
     *
     * @param device the device instance receiving the message
     * @param msg    the received message; must not be null
     */
    @Override
    public void handle(final Device device, final String msg) {
        super.handle(device, msg);
        switch (msg) {
            case "inside" -> device.changeState(new RestDeviceState());
            default -> {
            }
        }
    }

    /**
     * Returns a human-readable name for this state.
     *
     * @return the state name "LANDING"
     */
    @Override
    public String toString() {
        return "LANDING STATE";
    }

}
