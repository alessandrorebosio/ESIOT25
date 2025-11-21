package it.unibo.iot.view.impl;

import java.awt.Dimension;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.Serial;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Optional;
import java.util.function.Consumer;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

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

    private static final Map<String, Event> BUTTON_CONFIG = new LinkedHashMap<>();

    static {
        BUTTON_CONFIG.put("TAKE OFF", Event.TAKEOFF);
        BUTTON_CONFIG.put("LANDING", Event.LANDING);
        BUTTON_CONFIG.put("RESET", Event.RESET);
    }

    @Serial
    private static final long serialVersionUID = 1L;

    private static final int BUTTON_SPACING = 10;
    private static final int PANEL_PADDING = 15;
    private static final int BUTTON_WIDTH = 200;
    private static final int BUTTON_HEIGHT = 30;

    private transient Optional<Runnable> onClose = Optional.empty();
    private transient Optional<Consumer<Event>> listener = Optional.empty();

    /**
     * Creates the main application window and dynamically builds
     * the button panel based on {@link #BUTTON_CONFIG}.
     */
    public AppView() {
        super("Drone Hangar Unit");
        super.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void initialize() {
        final JPanel panel = buildPanel();
        this.add(panel);

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

    private JPanel buildPanel() {
        final JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        panel.setBorder(BorderFactory.createEmptyBorder(PANEL_PADDING, PANEL_PADDING, PANEL_PADDING, PANEL_PADDING));

        BUTTON_CONFIG.forEach((label, event) -> {
            final JButton btn = new JButton(label);
            btn.setMaximumSize(new Dimension(BUTTON_WIDTH, BUTTON_HEIGHT));
            btn.setAlignmentX(CENTER_ALIGNMENT);
            btn.addActionListener(e -> listener.ifPresent(l -> l.accept(event)));
            panel.add(btn);
            panel.add(Box.createRigidArea(new Dimension(0, BUTTON_SPACING)));
        });

        return panel;
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
