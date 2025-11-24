package it.unibo.iot.model.impl.states.alarm;

import it.unibo.iot.model.impl.states.AbstractSystemState;

/**
 * Represents the system state when an alarm condition is active.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class AlarmSystemState extends AbstractSystemState {

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return "ALARM";
    }
}
