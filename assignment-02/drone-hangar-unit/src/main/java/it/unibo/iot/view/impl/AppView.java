package it.unibo.iot.view.impl;

import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.Serial;
import java.util.Optional;
import java.util.function.Consumer;

import javax.swing.JFrame;

import it.unibo.iot.model.api.Event;
import it.unibo.iot.view.api.View;

/**
 * Swing-based implementation of the View interface.
 * Represents the main application window with close handling functionality.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class AppView extends JFrame implements View {

    @Serial
    private static final long serialVersionUID = 1L;

    private final ControlPanel panel;

    private transient Optional<Runnable> onClose = Optional.empty();
    private transient Optional<Consumer<Event>> listener = Optional.empty();

    /**
     * Creates the main application window and dynamically builds
     * the button panel based on {@link #BUTTON_CONFIG}.
     */
    public AppView() {
        super("Drone Hangar Unit");
        this.panel = new ControlPanel();
        super.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void initialize() {
        this.add(panel);
        this.panel.setActionListener(this::handleAction);

        super.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(final WindowEvent e) {
                AppView.this.onClose.ifPresent(Runnable::run);
            }
        });

        super.pack();
        super.setLocationRelativeTo(null);
        super.setVisible(true);
    }

    private void handleAction(final ActionEvent e) {
        final String cmd = e.getActionCommand();
        switch (cmd) {
            case "TAKEOFF" -> listener.ifPresent(l -> l.accept(Event.TAKEOFF));
            case "LANDING" -> listener.ifPresent(l -> l.accept(Event.LANDING));
            default -> { }
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void setOnClose(final Runnable onClose) {
        this.onClose = Optional.of(onClose);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void setEventListener(final Consumer<Event> l) {
        this.listener = Optional.of(l);
    }

    /**
     * {@inheritDoc}
     * Closes the view by dispatching a window closing event and disposing the
     * frame.
     */
    @Override
    public void close() {
        this.dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
        this.dispose();
    }
}
