package it.unibo.iot.model.api.states;

import it.unibo.iot.common.State;
import it.unibo.iot.model.api.Model;

public interface AppState extends State<Model> {

    void handle();

}
