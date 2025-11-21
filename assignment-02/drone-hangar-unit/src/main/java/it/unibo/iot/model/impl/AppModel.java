package it.unibo.iot.model.impl;

import java.util.Objects;

import it.unibo.iot.common.SystemState;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.states.AppState;

/**
 * Simple implementation of the Model interface that maintains a running state.
 * Uses volatile keyword to ensure thread-safe visibility of the running flag.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AppModel implements Model {

    private AppState state;

    private volatile boolean running;

    /**
     * {@inheritDoc}
     * Sets the running state to true.
     */
    @Override
    public void start() {
        this.running = true;
    }

    /**
     * {@inheritDoc}
     * Sets the running state to false.
     */
    @Override
    public void stop() {
        this.running = false;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public boolean isRunning() {
        return this.running;
    }

    @Override
    public void changeState(AppState newState) {
        if (this.state != null) {
            this.state.onEnter(this);
        }
        this.state = Objects.requireNonNull(newState, "The new state cannot be null.");
        this.state.onExit(this);
    }

    @Override
    public void handle(final SystemState state) {
        this.state.handle(this, state);
    }

    @Override
    public SystemState getState() {
        return this.state.getStateType();
    }

}
