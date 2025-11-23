package it.unibo.iot.common.api;

/**
 * Generic interface representing a state in a state machine.
 * 
 * @author Alessandro Rebosio
 * @param <T> the type of the context object passed to lifecycle methods
 * @since 1.0
 */
public interface State<T> {

    /**
     * Called when the state is entered.
     *
     * @param t the context object associated with the state transition
     */
    void onEnter(T t);

    /**
     * Called when the state is exited.
     *
     * @param t the context object associated with the state transition
     */
    void onExit(T t);

    /**
     * Called periodically (for example on every tick) to perform the state's
     * behaviour. Implementations should avoid long blocking operations and
     * keep this method responsive.
     *
     * @param t the context object used by the state during the update
     */
    void update(T t);

}
