package it.unibo.iot.view.api;

/**
 * Interface representing a view component in the application.
 * Provides methods to handle close events and programmatically close the view.
 * 
 * @author Alessandro Rebosio
 * @since 1.0
 */
public interface View {

    /**
     * Sets a callback to be executed when the view is requested to close.
     *
     * @param onClose the runnable to execute on close event, cannot be null
     */
    void setOnClose(Runnable onClose);

    /**
     * Closes the view and releases any associated resources.
     */
    void close();

}
