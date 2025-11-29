package it.unibo.iot.model.impl.states.normal;

import it.unibo.iot.common.api.Messages;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.impl.states.AbstractSystemState;
import it.unibo.iot.model.impl.states.prealarm.PreAlarmSystemState;

/**
 * Represents the normal operating state of the system.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public class NormalSystemState extends AbstractSystemState {

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final Model model, final String msg) {
        super.handle(model, msg);
        switch (Messages.fromString(msg)) {
            case PREALARM -> model.changeState(new PreAlarmSystemState());
            default -> {
            }
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return "NORMAL STATE";
    }

}
