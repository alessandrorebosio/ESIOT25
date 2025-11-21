package it.unibo.iot.model.impl;

import java.util.Objects;

import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.states.AppState;
import it.unibo.iot.model.impl.drone.Drone;

/**
 * Simple implementation of the Model interface that maintains a running state.
 * Uses volatile keyword to ensure thread-safe visibility of the running flag.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AppModel implements Model {

    private final Device device;
    private AppState state;

    private volatile boolean running;

    /**
     * Creates a new application model and initializes the drone
     * finite-state machine in the default state {@code DroneInsideState}.
     */
    public AppModel() {
        this(new Drone());
    }

    public AppModel(final Device device) {
        this.device = Objects.requireNonNull(device, "The device cannot be null.");
    }

    /**
     * {@inheritDoc}
     * Sets the running state to true.
     */
    @Override
    public void start() {
        this.running = true;
        this.state.onEnter(this);
    }

    /**
     * {@inheritDoc}
     * Sets the running state to false.
     */
    @Override
    public void stop() {
        this.running = false;
        this.state.onExit(this);
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
    public String getAppState() {
        return this.state.toString();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void changeState(final AppState newState) {
        if (this.state != null) {
            this.state.onExit(this);
        }
        this.state = newState;
        this.state.onEnter(this);
    }

}
