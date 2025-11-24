package it.unibo.iot.model.api.states;

import it.unibo.iot.common.api.State;
import it.unibo.iot.model.api.Model;

/**
 * Represents the overall state of the IoT system.
 * 
 * <p>
 * A {@code SystemState} defines the state of the entire {@link Model}.
 * </p>
 * 
 * @author Grazia Bochdanovits de Kavna
 */
public interface SystemState extends State<Model> {

    /**
     * Process the given textual message in the context of the provided model.
     *
     * @param model the model instance to be inspected or modified; must not be
     *              {@code null}
     * @param msg   the incoming message to handle; interpretation is
     *              implementation-dependent but
     *              should not be {@code null} or empty
     * @throws NullPointerException if {@code model} or {@code msg} is
     *                              {@code null} (implementations
     *                              may validate and throw)
     */
    void handle(Model model, String msg);

}
