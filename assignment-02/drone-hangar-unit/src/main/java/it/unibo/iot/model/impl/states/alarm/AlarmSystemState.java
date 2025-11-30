package it.unibo.iot.model.impl.states.alarm;

import it.unibo.iot.common.api.Messages;
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
        switch (Messages.fromString(msg)) {
            case NORMAL -> model.changeState(new NormalSystemState());
            default -> {
            }
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return "ALARM STATE\n" + super.toString();
    }

}
