package it.unibo.iot.model.impl.states.prealarm;

import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.impl.states.AbstractSystemState;
import it.unibo.iot.model.impl.states.alarm.AlarmSystemState;
import it.unibo.iot.model.impl.states.normal.NormalSystemState;

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
    public void handle(final Model model, final String msg) {
        super.handle(model, msg);
        switch (msg) {
            case "normal" -> model.changeState(new NormalSystemState());
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
        return "PREALARM STATE";
    }

}
