package it.unibo.iot.controller.impl.serial;

import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.Optional;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortDataListener;
import com.fazecast.jSerialComm.SerialPortEvent;

import it.unibo.iot.controller.api.serial.Connection;

/**
 * Implementation of the Connection interface for serial communication.
 * Manages serial port connections, data transmission, and reception using the
 * jSerialComm library.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public class SerialConnection implements Connection {

    private final Queue<String> receivedQueue;
    private SerialPort port;

    /**
     * Constructs a new SerialConnection using a newly created ConcurrentLinkedQueue
     * as the incoming message queue. This constructor delegates to the primary
     * constructor that accepts a queue, configuring the connection for the given
     * serial port name and baud rate.
     */
    public SerialConnection() {
        this(new ConcurrentLinkedQueue<>());
    }

    /**
     * Creates a new SerialConnection instance that will use the provided queue to
     * deliver
     * received data and will attempt to open the specified serial port with the
     * given baud rate.
     *
     * @param queue the queue used to enqueue received messages; must not be null
     * @throws NullPointerException if {@code queue} or {@code portName} is null
     */
    public SerialConnection(final Queue<String> queue) {
        this.receivedQueue = Objects.requireNonNull(queue, "The queue cannot be null.");
    }

    /**
     * Establishes a connection to the specified serial port.
     * 
     * @return true if connection was successful, false otherwise
     */
    @Override
    public boolean connect(final String portName, final int baudRate) {
        if (this.port == null) {
            this.port = SerialPort.getCommPort(portName);
            this.port.setBaudRate(baudRate);
        }

        if (this.port.openPort()) {
            this.port.removeDataListener();
            this.port.addDataListener(new SerialDataListener());
            this.receivedQueue.clear();
            return true;
        }

        return false;
    }

    /**
     * Closes the serial connection and releases resources.
     * Removes data listeners and clears the received message queue.
     *
     * @return true if disconnection was successful, false otherwise
     */
    @Override
    public boolean disconnect() {
        if (this.isConnected()) {
            this.port.removeDataListener();

            return this.port.closePort();
        }
        return true;
    }

    /**
     * Checks if the serial connection is currently open.
     *
     * @return true if the connection is open, false otherwise
     */
    @Override
    public boolean isConnected() {
        return this.port != null && this.port.isOpen();
    }

    /**
     * Sends a message through the serial connection.
     * Automatically appends a newline character if not present.
     *
     * @param message the message to send
     * @return true if the message was sent successfully, false otherwise
     */
    @Override
    public boolean send(final String message) {
        if (!this.isConnected()) {
            return false;
        }

        final String messageToSend = message.endsWith("\n") ? message : message + "\n";
        final byte[] data = messageToSend.getBytes(StandardCharsets.UTF_8);

        final int bytesWritten = this.port.writeBytes(data, data.length);
        return bytesWritten == data.length;
    }

    /**
     * Retrieves the next available received message from the queue.
     *
     * @return the received message, or null if no messages are available
     */
    @Override
    public Optional<String> receive() {
        return Optional.ofNullable(this.receivedQueue.poll());
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<String> getAvailablePort() {
        return Arrays.stream(SerialPort.getCommPorts())
                .map(SerialPort::getSystemPortPath)
                .toList();
    }

    /**
     * Internal class that handles serial data reception events.
     * Listens for data available events and processes incoming data.
     */
    private final class SerialDataListener implements SerialPortDataListener {

        private static final int MAX_MESSAGE_BUFFER = 4 * 1024;
        private static final int INITIAL_MESSAGE_BUFFER = 256;

        private char[] messageBuffer = new char[INITIAL_MESSAGE_BUFFER];
        private int bufferLen;

        /**
         * Specifies the types of events this listener is interested in.
         *
         * @return the listening events mask
         */
        @Override
        public int getListeningEvents() {
            return SerialPort.LISTENING_EVENT_DATA_AVAILABLE;
        }

        /**
         * Handles serial port events when data is available for reading.
         * Reads the available data and adds it to the received message queue.
         *
         * @param event the serial port event that occurred
         */
        @Override
        public void serialEvent(final SerialPortEvent event) {
            if (event.getEventType() != SerialPort.LISTENING_EVENT_DATA_AVAILABLE) {
                return;
            }

            final int availableBytes = port.bytesAvailable();
            if (availableBytes > 0) {
                final byte[] chunkBuffer = new byte[availableBytes];
                final int bytesRead = port.readBytes(chunkBuffer, chunkBuffer.length);

                if (bytesRead > 0) {
                    final String chunk = new String(chunkBuffer, 0, bytesRead, StandardCharsets.UTF_8);

                    for (final char c : chunk.toCharArray()) {
                        if (c == '\n' || c == '\r') {
                            if (bufferLen > 0) {
                                final String completeMessage = new String(messageBuffer, 0, bufferLen).trim();
                                if (!completeMessage.isEmpty()) {
                                    receivedQueue.add(completeMessage);
                                }
                                bufferLen = 0;
                            }
                        } else {
                            if (bufferLen >= messageBuffer.length) {
                                if (messageBuffer.length < MAX_MESSAGE_BUFFER) {
                                    final int newSize = Math.min(messageBuffer.length * 2, MAX_MESSAGE_BUFFER);
                                    final char[] newBuf = new char[newSize];
                                    System.arraycopy(messageBuffer, 0, newBuf, 0, bufferLen);
                                    messageBuffer = newBuf;
                                } else {
                                    bufferLen = 0;
                                }
                            }
                            messageBuffer[bufferLen] = c;
                            bufferLen++;
                        }
                    }
                }
            }
        }

    }

}
