package it.unibo.iot.model.impl.states.alarm;

import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.impl.states.AbstractSystemState;
import it.unibo.iot.model.impl.states.normal.NormalSystemState;

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
    public void handle(final Model model, final String msg) {
        super.handle(model, msg);
        switch (msg) {
            case "normal" -> model.changeState(new NormalSystemState());
            default -> {
            }
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return "ALARM STATE";
    }

}
