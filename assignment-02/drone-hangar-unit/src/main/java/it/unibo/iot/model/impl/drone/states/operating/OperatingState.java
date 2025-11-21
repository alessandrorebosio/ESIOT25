package it.unibo.iot.model.impl.drone.states.operating;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.EnumState;
import it.unibo.iot.model.impl.drone.states.AbstractDroneState;
import it.unibo.iot.model.impl.drone.states.landing.LandingState;

public class OperatingState extends AbstractDroneState {

    public void handle(final Device device, final EnumState event) {
        switch (event) {
            case LANDING -> {
                device.changeState(new LandingState());
            }
            default -> {
            }
        }
    }

    @Override
    public EnumState getState() {
        return EnumState.OPERATING;
    }

}
