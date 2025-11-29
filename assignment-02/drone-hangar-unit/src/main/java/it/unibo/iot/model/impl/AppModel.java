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
import it.unibo.iot.model.impl.states.unknown.UnknownSystemState;

/**
 * Simple implementation of the Model interface that maintains a running state.
 * Uses volatile keyword to ensure thread-safe visibility of the running flag.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AppModel implements Model {

    private final Queue<String> serial;
    private SystemState state;
    private final Device device;

    private volatile boolean running;

    /**
     * Creates a new {@code AppModel} with default components:
     * an empty message queue, an {@link UnknownSystemState}, and a {@link Drone}.
     */
    public AppModel() {
        this(new ConcurrentLinkedQueue<>(), new UnknownSystemState(), new Drone());
    }

    /**
     * Creates a new {@code AppModel} with the specified components.
     *
     * @param list   the message queue; must not be {@code null}.
     * @param state  the initial system state; must not be {@code null}.
     * @param device the device associated with the model; must not be {@code null}.
     */
    public AppModel(final Queue<String> list, final SystemState state, final Device device) {
        this.serial = Objects.requireNonNull(list, "The list cannot be null.");
        this.state = Objects.requireNonNull(state, "The state cannot be null.");
        this.device = Objects.requireNonNull(device, "The device cannot be null.");

        this.running = true;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void addMsg(final String msg) {
        this.serial.add(msg + "\n");
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Optional<String> take() {
        return Optional.ofNullable(this.serial.poll());
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

    /**
     * {@inheritDoc}
     */
    @Override
    public void handle(final String msg) {
        this.state.handle(this, msg);
        this.device.handle(msg);
        this.addMsg("received: " + msg);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void update() {
        this.state.update(this);
        this.device.update();
    }

    /**
     * {@inheritDoc}
     */
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

    /**
     * {@inheritDoc}
     */
    @Override
    public Device getDevice() {
        return this.device;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public DeviceState getDeviceState() {
        return this.device.getDeviceState();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public SystemState getAppState() {
        return this.state;
    }

}
