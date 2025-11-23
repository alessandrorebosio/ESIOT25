package it.unibo.iot.view.impl.panel.control;

import java.awt.GridLayout;
import java.io.Serial;

import javax.swing.JButton;

import it.unibo.iot.controller.api.Controller;
import it.unibo.iot.view.impl.panel.AbstractPanel;

/**
 * A control panel component containing drone control buttons for takeoff and
 * landing operations.
 * Provides a simple interface for sending commands to the drone controller.
 * 
 * @author Grazia Bochdanovits de Kavna
 * @since 1.0
 */
public final class ControlPanel extends AbstractPanel {

    private static final int ROWS = 2;
    private static final int COLS = 1;

    @Serial
    private static final long serialVersionUID = 1L;

    private final JButton takeoff = new JButton("TAKEOFF");
    private final JButton landing = new JButton("LANDING");

    /**
     * Constructs a new ControlPanel with takeoff and landing buttons.
     * Buttons are initially disabled and become enabled when the controller is
     * connected.
     *
     * @param controller the application controller used for sending drone commands
     */
    public ControlPanel(final Controller controller) {
        super(controller, "Drone Control");

        super.setLayout(new GridLayout(ROWS, COLS));

        this.takeoff.addActionListener(l -> controller.sendMsg(takeoff.getText()));

        this.landing.addActionListener(l -> controller.sendMsg(landing.getText()));

        super.add(this.takeoff);
        super.add(this.landing);
    }

    /**
     * Updates the panel state based on controller connection status.
     * Enables or disables the control buttons accordingly.
     *
     * @param controller the controller providing connection status information
     */
    @Override
    protected void update(final Controller controller) {
        this.takeoff.setEnabled(controller.isConnected());
        this.landing.setEnabled(controller.isConnected());
    }

}
