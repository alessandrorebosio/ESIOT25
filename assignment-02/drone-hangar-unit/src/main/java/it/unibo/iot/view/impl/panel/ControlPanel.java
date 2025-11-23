package it.unibo.iot.view.impl.panel;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionListener;
import java.io.Serial;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;

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

    private static final int BUTTON_WIDTH = 150;
    private static final int BUTTON_HEIGHT = 30;
    private static final int PADDING = 15;
    private static final int SPACING = 10;

    private final JLabel hangarStateLabel;
    private final JLabel droneStateLabel;

    private final JButton takeOffButton;
    private final JButton landingButton;

    /**
     * Builds a new {@code ControlPanel} with two state labels and three control
     * buttons.
     * The layout automatically centers all components inside the parent frame.
     */
    public ControlPanel() {
        super(new GridBagLayout());
        this.setBorder(new EmptyBorder(PADDING, PADDING, PADDING, PADDING));

        final JPanel innerPanel = new JPanel();
        innerPanel.setLayout(new BoxLayout(innerPanel, BoxLayout.Y_AXIS));
        innerPanel.setOpaque(false);

        this.droneStateLabel = new JLabel("Drone State Panel", SwingConstants.CENTER);
        this.hangarStateLabel = new JLabel("Hangar State Panel", SwingConstants.CENTER);
        this.droneStateLabel.setAlignmentX(CENTER_ALIGNMENT);
        this.hangarStateLabel.setAlignmentX(CENTER_ALIGNMENT);

        this.takeOffButton = createButton("TAKEOFF");
        this.landingButton = createButton("LANDING");

        innerPanel.add(droneStateLabel);
        innerPanel.add(Box.createRigidArea(new Dimension(0, SPACING)));
        innerPanel.add(hangarStateLabel);
        innerPanel.add(Box.createRigidArea(new Dimension(0, SPACING * 2)));
        innerPanel.add(takeOffButton);
        innerPanel.add(Box.createRigidArea(new Dimension(0, SPACING)));
        innerPanel.add(landingButton);

        final GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        this.add(innerPanel, gbc);
    }

    /**
     * Creates a button with a fixed maximum size and centered alignment.
     *
     * @param text the label text for the button
     * @return a configured {@link JButton}
     */
    private JButton createButton(final String text) {
        final JButton btn = new JButton(text);
        btn.setAlignmentX(CENTER_ALIGNMENT);
        btn.setMaximumSize(new Dimension(BUTTON_WIDTH, BUTTON_HEIGHT));
        return btn;
    }

    /**
     * Adds the same {@link ActionListener} to all control buttons.
     *
     * @param listener the listener to handle button actions
     */
    public void setActionListener(final ActionListener listener) {
        this.takeOffButton.addActionListener(listener);
        this.landingButton.addActionListener(listener);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void update() {
    }

}
