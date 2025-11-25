package it.unibo.iot.model.api.device.states;

import it.unibo.iot.common.api.State;
import it.unibo.iot.model.api.device.Device;

/**
 * Represents the operational state of a {@link Device}.
 * Each implementation defines a specific state in the device’s lifecycle,
 * such as takeoff, landing, rest, or operating.
 * 
 * <p>
 * Extends {@link State} to provide lifecycle methods like {@code onEnter},
 * {@code onExit}, and {@code update}.
 * </p>
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public interface DeviceState extends State<Device> {

    /**
     * Processes an incoming message in the context of the current device state.
     *
     * @param device the device instance to be operated on; must not be {@code null}
     * @param msg    the incoming message to process; interpretation is
     *               implementation-dependent but should not be {@code null} or
     *               empty
     * @throws NullPointerException if {@code device} or {@code msg} is
     *                              {@code null}
     */
    void handle(Device device, String msg);

}
