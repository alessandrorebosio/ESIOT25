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
}
