package it.unibo.iot.model.impl;

import java.util.Objects;

import it.unibo.iot.common.SystemState;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.states.AppState;
import it.unibo.iot.model.impl.states.normal.NormalState;

/**
 * Simple implementation of the Model interface that maintains a running state.
 * Uses volatile keyword to ensure thread-safe visibility of the running flag.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AppModel implements Model {

    /** The current application state; initialized to a safe default. */
    private AppState state = new NormalState();

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

    /**
     * {@inheritDoc}
     */
    @Override
    public void changeState(final AppState newState) {
        final AppState ns = Objects.requireNonNull(newState, "The new state cannot be null.");
        if (this.state != null) {
            this.state.onExit(this);
        }
        this.state = ns;
        this.state.onEnter(this);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final SystemState systemState) {
        this.state.handle(this, systemState);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public SystemState getState() {
        return this.state.getStateType();
    }

}
