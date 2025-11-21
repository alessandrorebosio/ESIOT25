package it.unibo.iot.model.api;

/**
 * Represents a domain event that triggers a state transition
 * in the drone finite-state machine.
 */
public enum Event {
    TAKEOFF,
    LANDING,
    RESET,
    TEMP_NORMAL,
    PRE_ALARM,
    ALARM
}
