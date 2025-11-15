package it.unibo.iot;

import java.util.Objects;

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
     * @param args optional CLI args: [port] [baudrate]
     */
    public static void main(final String[] args) {
        Objects.requireNonNull(args, "The args cannot be null");
        if (args.length < 2) {
            return;
        }

        new AppEngine(new AppController(args[0], Integer.parseInt(args[1])), new AppView()).run();
    }
}
