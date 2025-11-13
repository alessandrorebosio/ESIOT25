package it.unibo.iot.controller.impl;

import java.util.Objects;

import it.unibo.iot.controller.api.Controller;
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
     */
    @Override
    public boolean isRunning() {
        return this.model.isRunning();
    }

}
