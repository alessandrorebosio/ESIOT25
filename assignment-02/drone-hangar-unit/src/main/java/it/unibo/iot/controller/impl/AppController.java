package it.unibo.iot.controller.impl;

import java.util.List;
import java.util.Objects;

import it.unibo.iot.controller.api.Controller;
import it.unibo.iot.controller.api.serial.Connection;
import it.unibo.iot.controller.impl.serial.SerialConnection;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.impl.AppModel;

/**
 * Implementation of the Controller interface that manages the application state
 * by delegating operations to a Model instance and handling serial
 * communication.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AppController implements Controller {

    /** The serial connection handler for communication with external devices. */
    private final Connection connection;

    /** The application model managing business logic and state. */
    private final Model model;

    /**
     * Constructs an AppController with a default model.
     * Initializes a new serial connection instance.
     */
    public AppController() {
        this(new AppModel());
    }

    /**
     * Constructs an AppController with the specified model.
     *
     * @param model the model to be used by this controller, cannot be null
     * @throws NullPointerException if the model is null
     */
    public AppController(final Model model) {
        this.model = Objects.requireNonNull(model, "The model cannot be null.");
        this.connection = new SerialConnection();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void start() {
        this.model.start();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void stop() {
        this.model.stop();
    }

    /**
     * {@inheritDoc}
     * Receives data from the serial connection if connected.
     */
    @Override
    public void update() {
        if (this.isConnected()) {
            this.connection.receive();
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public boolean isRunning() {
        return this.model.isRunning();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<String> getAvailablePort() {
        return Connection.getAvailablePort();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public boolean isConnected() {
        return this.connection.isConnected();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public boolean connect(final String portName, final int baudRate) {
        return this.connection.connect(portName, baudRate);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public boolean disconnect() {
        return this.connection.disconnect();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void sendMsg(final String msg) {
        this.connection.send(msg);
    }

}
