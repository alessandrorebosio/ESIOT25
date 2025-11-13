package it.unibo.iot;

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
     * @param args unused
     */
    public static void main(final String[] args) {
        new AppEngine(new AppController(), new AppView()).run();
    }
}
