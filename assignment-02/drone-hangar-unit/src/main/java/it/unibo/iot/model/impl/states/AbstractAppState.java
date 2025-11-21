package it.unibo.iot.model.impl.states;

import it.unibo.iot.common.SystemState;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.states.AppState;
import it.unibo.iot.model.impl.states.alarm.AlarmState;
import it.unibo.iot.model.impl.states.normal.NormalState;
import it.unibo.iot.model.impl.states.prealarm.PreAlarmState;

/**
 * Base implementation of {@link AppState} providing common behaviour for
 * handling system state changes. Concrete states should override lifecycle
 * methods and the {@link #update(Model, float)} method.
 *
 * @author Alessandro Rebosio
 * @since 1.0
 */
public abstract class AbstractAppState implements AppState {

    /**
     * Called when entering the state. Default implementation does nothing.
     *
     * @param t the model entering the state
     */
    @Override
    public void onEnter(final Model t) {
    }

    /**
     * Called when exiting the state. Default implementation does nothing.
     *
     * @param t the model exiting the state
     */
    @Override
    public void onExit(final Model t) {
    }

    /**
     * Updates the state's internal logic. Concrete subclasses must implement
     * this method.
     *
     * @param t         the model being updated
     * @param deltaTime time elapsed since last update (seconds)
     */
    @Override
    public abstract void update(Model t, float deltaTime);

    /**
     * Handles an incoming {@link SystemState} and switches to the
     * corresponding concrete {@link AppState} implementation.
     *
     * @param model     the model that should change state
     * @param stateType the incoming system state
     */
    @Override
    public void handle(final Model model, final SystemState stateType) {
        switch (stateType) {
            case NORMAL -> model.changeState(new NormalState());
            case PREALARM -> model.changeState(new PreAlarmState());
            case ALARM -> model.changeState(new AlarmState());
        }
    }

}
