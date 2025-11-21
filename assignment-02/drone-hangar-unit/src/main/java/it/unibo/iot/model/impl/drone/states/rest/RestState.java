package it.unibo.iot.model.impl.drone.states.rest;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.EnumState;
import it.unibo.iot.model.impl.drone.states.AbstractDroneState;
import it.unibo.iot.model.impl.drone.states.takingoff.TakingoffState;

public class RestState extends AbstractDroneState {

    public void handle(final Device device, final EnumState event) {
        switch (event) {
            case TAKEOFF -> {
                device.changeState(new TakingoffState());
            }
            default -> {
            }
        }
    }

    @Override
    public EnumState getState() {
        return EnumState.REST;
    }

}
