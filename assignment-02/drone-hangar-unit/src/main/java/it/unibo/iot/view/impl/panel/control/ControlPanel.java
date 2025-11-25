package it.unibo.iot.view.impl.panel.control;

import java.awt.GridLayout;
import java.io.Serial;
import java.util.Locale;

import javax.swing.JButton;

import it.unibo.iot.controller.api.Controller;
import it.unibo.iot.model.impl.device.states.operating.OperatingDeviceState;
import it.unibo.iot.model.impl.device.states.rest.RestDeviceState;
import it.unibo.iot.model.impl.device.states.unknown.UnknownDeviceState;
import it.unibo.iot.model.impl.states.normal.NormalSystemState;
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

        super.setLayout(new GridLayout(2, 1));

        this.takeoff.addActionListener(l -> controller.sendMsg(this.takeoff.getText().toLowerCase(Locale.ROOT)));
        this.landing.addActionListener(l -> controller.sendMsg(this.landing.getText().toLowerCase(Locale.ROOT)));

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
        final boolean connectedAndNormal = controller.isConnected()
                && controller.getSystemState() instanceof NormalSystemState;

        this.takeoff.setEnabled(connectedAndNormal && (controller.getDeviceState() instanceof UnknownDeviceState
                || controller.getDeviceState() instanceof RestDeviceState));
        this.landing.setEnabled(connectedAndNormal && (controller.getDeviceState() instanceof UnknownDeviceState
                || controller.getDeviceState() instanceof OperatingDeviceState));
    }

}
