package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.states.AppState;

public abstract class AbstractAppState implements AppState {

    @Override
    public void onEnter(final Model t) {
    }

    @Override
    public void onExit(final Model t) {
    }

    @Override
    public void update(final Model t, final float deltaTime) {
    }

}
