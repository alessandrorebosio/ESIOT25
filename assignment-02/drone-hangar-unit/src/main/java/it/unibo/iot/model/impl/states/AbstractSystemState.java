package it.unibo.iot.model.impl.states;

import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.states.SystemState;

public abstract class AbstractSystemState implements SystemState {

    @Override
    public void onEnter(final Model t) {
    }

    @Override
    public void onExit(final Model t) {
    }

    @Override
    public void update(final Model t) {
    }

    @Override
    public abstract String toString();

}
