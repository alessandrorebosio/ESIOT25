package it.unibo.iot.model.impl;

import java.util.Objects;
import java.util.Optional;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.api.device.Device;
import it.unibo.iot.model.api.device.states.DeviceState;
import it.unibo.iot.model.api.states.SystemState;
import it.unibo.iot.model.impl.device.Drone;
import it.unibo.iot.model.impl.states.unkwown.UnknownSystemState;

/**
 * Simple implementation of the Model interface that maintains a running state.
 * Uses volatile keyword to ensure thread-safe visibility of the running flag.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AppModel implements Model {

    private final Queue<String> list;
    private SystemState state;
    private final Device device;

    private volatile boolean running;

    public AppModel() {
        this(new ConcurrentLinkedQueue<>(), new UnknownSystemState(), new Drone());
    }

    public AppModel(final Queue<String> list, final SystemState state, final Device device) {
        this.list = Objects.requireNonNull(list, "The list cannot be null.");
        this.changeState(Objects.requireNonNull(state, "The state cannot be null."));
        this.device = Objects.requireNonNull(device, "The device cannot be null.");
    }

    @Override
    public void addMsg(final String msg) {
        this.list.add(msg + "\n");
    }

    @Override
    public Optional<String> take() {
        return Optional.ofNullable(this.list.poll());
    }

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

    @Override
    public void changeState(final SystemState newState) {
        if (this.state != null) {
            this.state.onExit(this);
        }
        this.state = newState;
        this.state.onEnter(this);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public boolean isRunning() {
        return this.running;
    }

    @Override
    public DeviceState getDeviceState() {
        return this.device.getDeviceState();
    }

    @Override
    public SystemState getAppState() {
        return this.state;
    }
}
