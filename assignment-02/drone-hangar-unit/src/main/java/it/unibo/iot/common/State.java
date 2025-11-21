package it.unibo.iot.common;

/**
 * Generic interface for representing a state in a finite-state machine.
 * 
 * @author Grazia Bochdanovits de Kavna
 * 
 * @param <T> the context (model) associated with this state
 */
public interface State<T> {

    /**
     * Called when entering this state.
     *
     * @param t the model entering the state
     */
    void onEnter(final T t);

    /**
     * Called when exiting this state.
     *
     * @param t the model leaving the state
     */
    void onExit(final T t);

    /**
     * Updates the state logic.
     *
     * @param t         the context or owner being updated
     * @param deltaTime the time elapsed since the last update (in seconds)
     */
    void update(final T t, final float deltaTime);

}
