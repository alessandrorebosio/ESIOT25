package it.unibo.iot.model.api;

/**
 * Functional interface representing a component capable of sending
 * string-based commands to an external system (e.g., a serial connection).
 * Used by the Model to emit commands without depending on specific I/O details.
 * 
 * @author Grazia Bochdanovits de Kavna
 */
@FunctionalInterface
public interface CommandSender {

    /**
     * Sends a command to the underlying communication channel.
     *
     * @param command the command string to send, never null
     */
    void send(String command);
}
