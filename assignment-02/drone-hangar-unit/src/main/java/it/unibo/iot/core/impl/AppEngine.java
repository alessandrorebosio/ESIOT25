package it.unibo.iot.core.impl;

import java.util.Objects;

import it.unibo.iot.controller.api.Controller;
import it.unibo.iot.core.api.Engine;
import it.unibo.iot.view.api.View;

/**
 * Implementation of the Engine interface that manages the main application
 * loop.
 * Coordinates between the controller and view components.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AppEngine implements Engine {

    private static final long PERIOD = 100;

    private final Controller controller;
    private final View view;

    /**
     * Constructs an AppEngine with the specified controller and view.
     *
     * @param controller the controller to be used, cannot be null
     * @param view       the view to be used, cannot be null
     * @throws NullPointerException if controller or view is null
     */
    public AppEngine(final Controller controller, final View view) {
        this.controller = Objects.requireNonNull(controller, "The controller cannot be null.");
        this.view = Objects.requireNonNull(view, "The view cannot be null.");

        this.view.setOnClose(this.controller::stop);
    }

    /**
     * {@inheritDoc}
     * Starts the main application loop which runs until the controller stops.
     * The loop sleeps for a fixed period between iterations.
     */
    @Override
    public void run() {
        this.controller.start();

        while (this.controller.isRunning()) {
            try {
                this.controller.update();

                Thread.sleep(PERIOD);
            } catch (final InterruptedException e) {
                Thread.currentThread().interrupt();
                break;
            }
        }
        this.stop();
    }

    /**
     * {@inheritDoc}
     * Stops the engine by closing the view.
     */
    @Override
    public void stop() {
        this.view.close();
    }

}
