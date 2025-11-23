package it.unibo.iot;

import it.unibo.iot.controller.api.Controller;
import it.unibo.iot.controller.impl.AppController;
import it.unibo.iot.core.impl.AppEngine;
import it.unibo.iot.view.impl.AppView;

/**
 * Entry point of the app.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public final class App {

    private App() {
    }

    /**
     * Starts the application.
     *
     * @param args not used
     */
    public static void main(final String[] args) {
        final Controller controller = new AppController();
        new AppEngine(controller, new AppView(controller)).run();
    }
}
