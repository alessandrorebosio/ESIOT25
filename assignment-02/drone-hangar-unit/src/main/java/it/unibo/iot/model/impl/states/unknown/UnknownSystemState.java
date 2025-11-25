package it.unibo.iot.model.impl.states.unknown;

import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.impl.states.AbstractSystemState;
import it.unibo.iot.model.impl.states.alarm.AlarmSystemState;
import it.unibo.iot.model.impl.states.normal.NormalSystemState;
import it.unibo.iot.model.impl.states.prealarm.PreAlarmSystemState;

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
    public void handle(final Model model, final String msg) {
        super.handle(model, msg);
        switch (msg) {
            case "normal" -> model.changeState(new NormalSystemState());
            case "prealarm" -> model.changeState(new PreAlarmSystemState());
            case "alarm" -> model.changeState(new AlarmSystemState());
            default -> {
            }
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return "UNKNOWN STATE";
    }

}
