package it.unibo.iot.view.api;

import java.util.function.Consumer;

import it.unibo.iot.model.api.Event;

/**
 * Interface representing a view component in the application.
 * Provides methods to handle close events and programmatically close the view.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public interface View {

    /**
     * Initializes the view components and makes the UI ready for display.
     */
    void initialize();

    /**
     * Sets a callback to be executed when the view is requested to close.
     *
     * @param onClose the runnable to execute on close event, cannot be null
     */
    void setOnClose(Runnable onClose);

    /**
     * Registers a listener invoked whenever the user triggers an action
     * in the view (e.g., pressing TAKEOFF, LANDING, or RESET buttons).
     *
     * @param listener the callback to notify UI events, cannot be null.
     */
    void setEventListener(Consumer<Event> listener);

    /**
     * Closes the view and releases any associated resources.
     */
    void close();

}
