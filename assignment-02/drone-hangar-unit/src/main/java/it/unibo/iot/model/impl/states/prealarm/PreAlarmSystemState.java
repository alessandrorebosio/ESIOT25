package it.unibo.iot.model.impl.states.prealarm;

import it.unibo.iot.model.impl.states.AbstractSystemState;

/**
 * Represents the system state when a pre-alarm condition is detected.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class PreAlarmSystemState extends AbstractSystemState {

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return "PREALARM";
    }
}
