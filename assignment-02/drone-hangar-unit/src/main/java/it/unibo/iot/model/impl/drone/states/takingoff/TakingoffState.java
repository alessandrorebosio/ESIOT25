package it.unibo.iot.model.impl.drone.states.takingoff;

import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.EnumState;
import it.unibo.iot.model.impl.drone.states.AbstractDroneState;
import it.unibo.iot.model.impl.drone.states.operating.OperatingState;

public class TakingoffState extends AbstractDroneState {

    @Override
    public void handle(final Device device, final EnumState event) {
        switch (event) {
            case OPERATING -> {
                device.changeState(new OperatingState());
            }
            default -> {
            }
        }
    }

    @Override
    public EnumState getState() {
        return EnumState.TAKEOFF;
    }

}
