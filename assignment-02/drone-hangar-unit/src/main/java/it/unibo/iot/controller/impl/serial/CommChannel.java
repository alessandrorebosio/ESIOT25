package it.unibo.iot.controller.impl.serial;

import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.Optional;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

import it.unibo.iot.controller.api.serial.Connection;
import jssc.SerialPort;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;
import jssc.SerialPortList;

/**
 * Implementation of a serial communication channel using JSSC (Java Simple
 * Serial Connector).
 * 
 * @author Alessandro Rebosio
 * @version 1.0
 * @see Connection
 * @see SerialPortEventListener
 */
public class CommChannel implements Connection, SerialPortEventListener {

    private final Queue<String> queue;
    private String currentMsg = "";
    private SerialPort port;

    /**
     * Constructs a new CommChannel with a default concurrent queue.
     */
    public CommChannel() {
        this(new ConcurrentLinkedQueue<>());
    }

    /**
     * Constructs a new CommChannel with the specified queue implementation.
     * 
     * @param queue the queue to use for message storage, must not be null
     * @throws NullPointerException if the provided queue is null
     */
    public CommChannel(final Queue<String> queue) {
        this.queue = Objects.requireNonNull(queue, "The queue cannot be null.");
    }

    /**
     * Establishes a connection to the specified serial port.
     * 
     * @param portName the name of the serial port (e.g., "COM3" on Windows,
     *                 "/dev/ttyUSB0" on Linux)
     * @param baudRate the baud rate for communication (e.g., 9600, 115200)
     * @return true if connection was successfully established, false otherwise
     */
    @Override
    public boolean connect(final String portName, final int baudRate) {
        try {
            this.port = new SerialPort(portName);
            this.port.openPort();

            this.port.setParams(baudRate,
                    SerialPort.DATABITS_8,
                    SerialPort.STOPBITS_1,
                    SerialPort.PARITY_NONE);

            this.port.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN | SerialPort.FLOWCONTROL_RTSCTS_OUT);

            this.port.addEventListener(this);

            /*
             * drop any previously received data so we don't deliver messages
             * that arrived before this explicit connect call
             */
            this.currentMsg = "";
            this.queue.clear();

            return true;
        } catch (final SerialPortException ex) {
            return false;
        }
    }

    /**
     * Closes the serial port connection and removes the event listener.
     * 
     * @return true if disconnection was successful, false otherwise
     */
    @Override
    public boolean disconnect() {
        if (this.port == null) {
            return false;
        }
        try {
            this.port.removeEventListener();
            return this.port.closePort();
        } catch (final SerialPortException ex) {
            return false;
        } finally {
            /* clear buffer and queue on disconnect to avoid stale messages */
            this.currentMsg = "";
            this.queue.clear();
            this.port = null;
        }
    }

    /**
     * Checks if the communication channel is currently connected.
     * 
     * @return true if the serial port is initialized and open, false otherwise
     */
    @Override
    public boolean isConnected() {
        return this.port != null && this.port.isOpened();
    }

    /**
     * Sends a message through the serial port.
     * 
     * @param message the message to send, null messages are converted to empty
     *                strings
     * @return true if the message was successfully sent, false otherwise
     */
    @Override
    public boolean send(final String message) {
        if (this.port == null || !this.port.isOpened()) {
            return false;
        }
        try {
            final String msg = message == null ? "" : message;
            final byte[] bytes = msg.getBytes(StandardCharsets.UTF_8);
            return this.port.writeBytes(bytes);
        } catch (final SerialPortException ex) {
            return false;
        }
    }

    /**
     * Retrieves the next available received message from the queue.
     * 
     * @return an Optional containing the next message if available, empty Optional
     *         otherwise
     */
    @Override
    public Optional<String> receive() {
        return Optional.ofNullable(this.queue.poll());
    }

    /**
     * Retrieves a list of available serial ports on the system.
     * 
     * @return a list of serial port names available for connection
     */
    @Override
    public List<String> getAvailablePort() {
        return Arrays.stream(SerialPortList.getPortNames()).toList();
    }

    /**
     * Handles serial port events for incoming data.
     * 
     * @param event the serial port event containing information about the received
     *              data
     */
    @SuppressWarnings("PMD.EmptyCatchBlock")
    @Override
    public synchronized void serialEvent(final SerialPortEvent event) {
        if (!event.isRXCHAR() || event.getEventValue() <= 0 || port == null || !port.isOpened()) {
            return;
        }
        try {
            final byte[] bytes = port.readBytes(event.getEventValue());
            if (bytes == null || bytes.length == 0) {
                return;
            }

            final String chunk = new String(bytes, StandardCharsets.UTF_8);
            final StringBuilder buf = new StringBuilder(currentMsg.length() + chunk.length());
            buf.append(currentMsg).append(chunk);

            final StringBuilder line = new StringBuilder();
            final int n = buf.length();
            for (int i = 0; i < n; i++) {
                final char c = buf.charAt(i);
                if (c == '\n') {
                    queue.add(line.toString());
                    line.setLength(0);
                } else if (c != '\r') {
                    line.append(c);
                }
            }
            currentMsg = line.toString();
        } catch (final SerialPortException ex) {
            // ignore exceptions on read; nothing to do here
        }
    }
}
