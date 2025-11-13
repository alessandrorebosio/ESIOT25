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

    private static final String PORT = "/dev/cu.usbmodem11201";
    private static final int BAUDRATE = 9600;

    private final Connection connection;
    private final Model model;

    /**
     * Constructs an AppController with a default AppModel.
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
        if (this.connection.isPortAvailable(PORT)
                && this.connection.connect(PORT, BAUDRATE)) {
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
        if (this.connection.isConnected()
                && this.connection.isConnectionActive()) {
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
