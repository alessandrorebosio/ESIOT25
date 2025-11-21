package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.states.AppState;

public abstract class AbstractAppState implements AppState {

    @Override
    public void onEnter(Model t) {
    }

    @Override
    public void onExit(Model t) {
    }

    @Override
    public void update(Model t, float deltaTime) {
    }

}
