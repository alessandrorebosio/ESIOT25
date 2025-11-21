package it.unibo.iot.model.impl;

import it.unibo.iot.model.api.CommandSender;
import it.unibo.iot.model.api.Event;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.states.DroneState;
import it.unibo.iot.model.impl.states.AlarmState;
import it.unibo.iot.model.impl.states.DroneInsideState;
import it.unibo.iot.model.impl.states.PreAlarmState;

/**
 * Simple implementation of the Model interface that maintains a running state.
 * Uses volatile keyword to ensure thread-safe visibility of the running flag.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AppModel implements Model {

    private volatile boolean running;

    private DroneState currentState;
    private DroneState previousState;

    private CommandSender commandSender = cmd -> { };

    /**
     * Creates a new application model and initializes the drone
     * finite-state machine in the default state {@code DroneInsideState}.
     */
    public AppModel() {
        this.currentState = new DroneInsideState();
        this.previousState = this.currentState;
    }

    /**
     * {@inheritDoc}
     * Sets the running state to true.
     */
    @Override
    public void start() {
        this.running = true;
        this.currentState.onEnter(this);
    }

    /**
     * {@inheritDoc}
     * Sets the running state to false.
     */
    @Override
    public void stop() {
        this.running = false;
        this.currentState.onExit(this);
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
    public void handle(final Event event) {
        this.currentState.handle(this, event);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void setState(final DroneState newState) {
        if (!(newState instanceof PreAlarmState) && !(newState instanceof AlarmState)) {
            this.previousState = newState;
        }
        this.currentState.onExit(this);
        this.currentState = newState;
        this.currentState.onEnter(this);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String getCurrentState() {
        return this.currentState.toString();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public DroneState getPreviousState() {
        return this.previousState;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void setCommandSender(final CommandSender cmd) {
        this.commandSender = cmd;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void sendCommand(final String cmd) {
        this.commandSender.send(cmd);
    }
}
