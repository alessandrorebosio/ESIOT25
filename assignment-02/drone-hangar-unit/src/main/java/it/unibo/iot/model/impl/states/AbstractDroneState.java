package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.DroneModel;
import it.unibo.iot.model.api.Event;
import it.unibo.iot.model.api.states.DroneState;

/**
 * Base class for drone states providing default behavior
 * for transitions and naming.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public abstract class AbstractDroneState implements DroneState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void onEvent(final Event event) {
        // default no-op
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final DroneModel model, final Event event) {
        // default: no transition
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void onEnter(final DroneModel model) {
        // default empty
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void onExit(final DroneModel model) {
        // default empty - can be overridden
    }

    /**
     * Returns a textual representation of this state.
     * 
     * @return the name of the concrete drone state
     */
    @Override
    public String toString() {
        return "[DRONESTATE] " + this.getClass().getSimpleName();
    }
}
