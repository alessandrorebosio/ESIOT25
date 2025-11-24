package it.unibo.iot.model.impl.states.unknown;

import it.unibo.iot.model.impl.states.AbstractSystemState;

/**
 * Represents an undefined or unknown system state.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class UnknownSystemState extends AbstractSystemState {

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return "UNKNOWN";
    }
}
