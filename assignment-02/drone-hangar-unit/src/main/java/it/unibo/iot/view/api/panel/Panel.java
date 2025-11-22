package it.unibo.iot.view.api.panel;

/**
 * A minimal view panel contract.
 * 
 * @author Alesssandro Rebosio
 * @since 1.0
 */
@FunctionalInterface
public interface Panel {

    /**
     * Update the panel state and refresh its contents.
     */
    void update();

}
