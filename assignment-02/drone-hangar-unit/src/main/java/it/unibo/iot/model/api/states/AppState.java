package it.unibo.iot.model.api.states;

import it.unibo.iot.common.State;
import it.unibo.iot.common.SystemState;
import it.unibo.iot.model.api.Model;

/**
 * Represents a state of the application model. Implementations describe how
 * the model reacts to {@link SystemState} changes and provide lifecycle
 * callbacks.
 *
 * @author Alessandro Rebosio
 * @since 1.0
 */
public interface AppState extends State<Model> {

    /**
     * Handles a state transition request described by {@code stateType}.
     *
     * @param model     the model that owns this state
     * @param stateType the new system state to handle
     */
    void handle(Model model, SystemState stateType);

    /**
     * Returns the {@link SystemState} value that corresponds to this
     * AppState implementation.
     *
     * @return the SystemState value
     */
    SystemState getStateType();

}
