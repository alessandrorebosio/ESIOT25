package it.unibo.iot.view.impl.panel.monitor;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.io.Serial;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JPanel;

import it.unibo.iot.controller.api.Controller;
import it.unibo.iot.view.impl.panel.AbstractPanel;

/**
 * A panel for managing serial connection settings and communication.
 * Provides interface elements for port selection, baud rate configuration,
 * connection management, and message sending.
 * 
 * @author Unknown
 * @since 1.0
 */
public class MonitorPanel extends AbstractPanel {

    @Serial
    private static final long serialVersionUID = 1L;

    private static final int GAPS = 5;

    private final JComboBox<String> box = new JComboBox<>();
    private final JTextField baud = new JTextField(8);
    private final JButton connect = new JButton("Connect");
    private final JButton disconnect = new JButton("Disconnect");
    private final JTextArea textArea = new JTextArea();
    private final JScrollPane scrollPane = new JScrollPane(this.textArea);
    /** When true, incoming messages will force the view to scroll to bottom. */
    private boolean autoScroll = true;
    private final JTextField message = new JTextField();
    private final JButton send = new JButton("send");
    private final JButton clear = new JButton("clear");

    private int availablePort;

    /**
     * Constructs a new ConnectionPanel with all connection management components.
     *
     * @param controller the application controller used for connection operations
     */
    public MonitorPanel(final Controller controller) {
        super(controller, "Connection");

        super.setLayout(new BorderLayout(GAPS, GAPS));

        final JPanel top = new JPanel(new FlowLayout(FlowLayout.LEFT, GAPS, GAPS));

        controller.getAvailablePort().forEach(this.box::addItem);
        this.availablePort = controller.getAvailablePort().size();

        this.baud.setText("9600");

        this.connect.addActionListener(l -> {
            try {
                final int baudRate = Integer.parseInt(this.baud.getText());
                controller.connect((String) this.box.getSelectedItem(), baudRate);
            } catch (final NumberFormatException ex) {
                JOptionPane.showMessageDialog(
                        this,
                        "Invalid baud rate value. Please enter an integer (e.g. 9600).",
                        "Input Error",
                        JOptionPane.ERROR_MESSAGE);
                this.baud.setText("");
            }
        });

        this.disconnect.addActionListener(l -> controller.disconnect());

        top.add(new JLabel("Port:"));
        top.add(this.box);
        top.add(new JLabel("Baud:"));
        top.add(this.baud);
        top.add(this.connect);
        top.add(this.disconnect);

        super.add(top, BorderLayout.NORTH);

        this.textArea.setEditable(false);
        super.add(this.scrollPane, BorderLayout.CENTER);

        final JScrollBar vertical = this.scrollPane.getVerticalScrollBar();
        vertical.addAdjustmentListener(e -> {
            final int extent = vertical.getModel().getExtent();
            final int max = vertical.getMaximum();
            final int value = vertical.getValue();
            this.autoScroll = value + extent >= max;
        });

        final JPanel bottom = new JPanel(new BorderLayout(GAPS, 0));

        this.send.addActionListener(l -> {
            controller.sendMsg(this.message.getText());
            this.message.setText("");
        });

        this.clear.addActionListener(l -> {
            this.textArea.setText("");
            this.autoScroll = true;
            this.scrollPane.getVerticalScrollBar().setValue(0);
        });

        bottom.add(this.message, BorderLayout.CENTER);

        final JPanel east = new JPanel(new FlowLayout(FlowLayout.RIGHT, GAPS, 0));
        east.add(this.send);
        east.add(this.clear);
        bottom.add(east, BorderLayout.EAST);

        super.add(bottom, BorderLayout.SOUTH);
    }

    /**
     * Updates the panel state based on controller connection status.
     * Enables or disables message input components accordingly.
     *
     * @param controller the controller providing connection status information
     */
    @Override
    protected void update(final Controller controller) {
        final int port = controller.getAvailablePort().size();
        if (port != availablePort) {
            this.box.removeAllItems();
            controller.getAvailablePort().forEach(this.box::addItem);
            this.availablePort = port;
        }

        this.connect.setEnabled(!controller.isConnected());
        this.disconnect.setEnabled(controller.isConnected());

        this.message.setEnabled(controller.isConnected());
        this.send.setEnabled(controller.isConnected());

        controller.message().ifPresent(m -> {
            this.textArea.append(m);
            if (this.autoScroll) {
                textArea.setCaretPosition(textArea.getDocument().getLength());
            }
        });
    }

}
