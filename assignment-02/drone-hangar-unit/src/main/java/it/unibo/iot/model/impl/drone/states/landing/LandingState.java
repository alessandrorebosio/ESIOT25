package it.unibo.iot.model.impl.drone.states.landing;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.EnumState;
import it.unibo.iot.model.impl.drone.states.AbstractDroneState;
import it.unibo.iot.model.impl.drone.states.rest.RestState;

public class LandingState extends AbstractDroneState {

    public void handle(final Device device, final EnumState event) {
        switch (event) {
            case REST -> {
                device.changeState(new RestState());
            }
            default -> {
            }
        }
    }

    @Override
    public EnumState getState() {
        return EnumState.LANDING;
    }
}
