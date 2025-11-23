package it.unibo.iot.view.impl;

import java.awt.GridLayout;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.Serial;
import java.util.Arrays;
import java.util.Optional;

import javax.swing.JFrame;

import it.unibo.iot.controller.api.Controller;
import it.unibo.iot.view.api.View;
import it.unibo.iot.view.impl.panel.AbstractPanel;
import it.unibo.iot.view.impl.panel.connection.ConnectionPanel;
import it.unibo.iot.view.impl.panel.control.ControlPanel;
import it.unibo.iot.view.impl.panel.status.StatusPanel;

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

    private transient Optional<Runnable> onClose = Optional.empty();

    /**
     * Constructs and displays the main application window for the Drone Hangar
     * Unit.
     *
     * @param controller the controller instance used to initialize the child
     *                   panels; must not be {@code null}
     */
    public AppView(final Controller controller) {
        super("Drone Hangar Unit");

        super.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);

        super.setLayout(new GridLayout(3, 1));

        super.add(new ConnectionPanel(controller));
        super.add(new ControlPanel(controller));
        super.add(new StatusPanel(controller));

        super.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(final WindowEvent e) {
                AppView.this.onClose.ifPresent(Runnable::run);
            }
        });

        super.setLocationRelativeTo(null);
        super.setVisible(true);
        super.pack();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void setOnClose(final Runnable onClose) {
        this.onClose = Optional.ofNullable(onClose);
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

    /**
     * {@inheritDoc}
     */
    @Override
    public void update() {
        Arrays.stream(super.getContentPane().getComponents())
                .filter(AbstractPanel.class::isInstance)
                .map(AbstractPanel.class::cast)
                .forEach(AbstractPanel::update);
    }

}
