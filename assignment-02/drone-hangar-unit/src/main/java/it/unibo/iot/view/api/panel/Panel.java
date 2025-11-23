package it.unibo.iot.view.api.panel;

/**
 * A minimal view panel contract defining the basic operations
 * that all panel implementations must provide.
 * 
 * @author Alesssandro Rebosio
 * @since 1.0
 */
@SuppressWarnings("PMD.ImplicitFunctionalInterface")
public interface Panel {

    /**
     * Updates the panel state and refreshes its contents.
     */
    void update();

}
