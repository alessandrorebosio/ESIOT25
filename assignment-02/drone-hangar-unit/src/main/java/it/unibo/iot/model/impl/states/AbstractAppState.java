package it.unibo.iot.model.impl.states;

import it.unibo.iot.common.SystemState;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.states.AppState;
import it.unibo.iot.model.impl.states.alarm.AlarmState;
import it.unibo.iot.model.impl.states.normal.NormalState;
import it.unibo.iot.model.impl.states.prealarm.PreAlarmState;

public abstract class AbstractAppState implements AppState {

    @Override
    public void onEnter(Model t) {
    }

    @Override
    public void onExit(Model t) {
    }

    @Override
    public abstract void update(Model t, float deltaTime);

    @Override
    public void handle(Model model, SystemState stateType) {
        switch (stateType) {
            case NORMAL -> {
                model.changeState(new NormalState());
            }
            case PREALARM -> {
                model.changeState(new PreAlarmState());
            }
            case ALARM -> {
                model.changeState(new AlarmState());
            }
        }
    }

}
