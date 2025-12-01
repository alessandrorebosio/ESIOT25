package it.unibo.iot.view.impl.panel.status;

import java.awt.GridLayout;
import java.io.Serial;

import javax.swing.JLabel;

import it.unibo.iot.controller.api.Controller;
import it.unibo.iot.view.impl.panel.AbstractPanel;

/**
 * StatusPanel is a GUI panel that displays the status information for
 * a hangar and a drone in a vertical layout.
 * 
 * <p>
 * This panel extends {@link AbstractPanel} and provides a simple
 * interface to show status updates for system components. It displays
 * two centered labels for hangar and drone status information.
 * </p>
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class StatusPanel extends AbstractPanel {

    @Serial
    private static final long serialVersionUID = 1L;

    private final JLabel hangarLabel = new JLabel("", JLabel.CENTER);
    private final JLabel temperatureLabel = new JLabel("", JLabel.CENTER);
    private final JLabel droneLabel = new JLabel("", JLabel.CENTER);
    private final JLabel distanceLabel = new JLabel("", JLabel.CENTER);

    /**
     * Constructs a new StatusPanel with a grid layout containing two rows and one
     * column. Initializes and centers the hangar and drone labels within the panel.
     *
     * @param controller the application controller used for accessing status
     *                   information
     * @throws NullPointerException if the controller is null
     */
    public StatusPanel(final Controller controller) {
        super(controller, "Status");

        super.setLayout(new GridLayout(4, 1));

        this.hangarLabel.setVerticalAlignment(JLabel.CENTER);
        super.add(hangarLabel);

        this.temperatureLabel.setVerticalAlignment(JLabel.CENTER);
        super.add(this.temperatureLabel);

        this.droneLabel.setVerticalAlignment(JLabel.CENTER);
        super.add(this.droneLabel);

        this.distanceLabel.setVerticalAlignment(JLabel.CENTER);
        super.add(this.distanceLabel);
    }

    /**
     * Updates the panel by setting the text for both hangar and drone labels
     * with information retrieved from the controller. This method populates
     * the labels with current status information from the application state.
     *
     * @param controller the controller used to retrieve current status information
     */
    @Override
    public void update(final Controller controller) {
        this.hangarLabel.setText("HANGAR: " + controller.getSystemState());
        this.temperatureLabel.setText("TEMPERATURE: " + controller.getSystemTemperature() + "°C");
        this.droneLabel.setText("DRONE: " + controller.getDeviceState());
        this.distanceLabel.setText("DISTANCE: " + controller.getDroneDistance() + " cm");
    }

}
