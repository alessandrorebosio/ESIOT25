package it.unibo.iot.view.impl.panel;

import java.io.Serial;
import javax.swing.JPanel;

import it.unibo.iot.view.api.panel.Panel;

/**
 * A control panel component containing two labels and three buttons.
 * The entire content is centered both horizontally and vertically.
 * 
 * <p>
 * Buttons: TAKEOFF and LANDING.
 * Labels: Drone State and Hangar State.
 * </p>
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public final class ControlPanel extends JPanel implements Panel {

    @Serial
    private static final long serialVersionUID = 1L;

    public ControlPanel() {

    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void update() {
    }

}
