package it.unibo.iot.controller.impl;

import java.util.Objects;

import it.unibo.iot.controller.api.Controller;
import it.unibo.iot.controller.api.serial.Connection;
import it.unibo.iot.controller.impl.serial.SerialConnection;
import it.unibo.iot.model.api.Model;
import it.unibo.iot.model.impl.AppModel;

/**
 * Implementation of the Controller interface that manages the application state
 * by delegating operations to a Model instance.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AppController implements Controller {

    private final Connection connection;
    private final Model model;
    private final String port;
    private final int baudrate;

    /**
     * Constructs an AppController with the specified port and baudrate using a
     * default model.
     *
     * @param port     the serial port to use, cannot be null
     * @param baudrate the baud rate to use
     */
    public AppController(final String port, final int baudrate) {
        this(new AppModel(), port, baudrate);
    }

    /**
     * Constructs an AppController with the specified model, port and baudrate.
     *
     * @param model    the model to be used by this controller, cannot be null
     * @param port     the serial port to use, cannot be null
     * @param baudrate the baud rate to use
     * @throws NullPointerException if the model or port is null
     */
    public AppController(final Model model, final String port, final int baudrate) {
        this.model = Objects.requireNonNull(model, "The model cannot be null.");
        this.port = Objects.requireNonNull(port, "The port cannot be null.");
        this.connection = new SerialConnection();

        this.baudrate = baudrate;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void start() {
        if (this.connection.isPortAvailable(this.port)
                && this.connection.connect(this.port, this.baudrate)) {
            this.model.start();
        }
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
     */
    @Override
    public void update() {
        if (this.connection.isConnected()) {
            this.connection.receive().ifPresent(System.out::println);
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public boolean isRunning() {
        return this.model.isRunning();
    }

}
