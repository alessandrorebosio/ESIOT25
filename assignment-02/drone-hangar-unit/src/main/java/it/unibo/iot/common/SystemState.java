package it.unibo.iot.common;

import java.util.Optional;

/**
 * Enumeration of high-level system states used by the application model.
 * Each enum constant holds a string representation used for serialization
 * and simple text-based transport (for example, messages received from a
 * serial connection).
 *
 * @author Alessandro Rebosio
 * @since 1.0
 */
public enum SystemState {

    /** The normal operating state. */
    NORMAL("normal"),

    /** Transitional pre-alarm state. */
    PREALARM("prealarm"),

    /** Alarm state indicating an active alarm condition. */
    ALARM("alarm");

    private final String value;

    /**
     * Creates a SystemState with the given textual representation.
     *
     * @param value the string value for this state, not null
     */
    SystemState(final String value) {
        this.value = value;
    }

    /**
     * Returns the string representation of the state.
     *
     * @return the textual value of this state
     */
    @Override
    public String toString() {
        return value;
    }

    /**
     * Parses the given string and returns an {@link Optional} with the
     * corresponding {@link SystemState}. The comparison is case-insensitive
     * and leading/trailing whitespace is ignored.
     *
     * @param s the string to parse, may be null
     * @return an Optional containing the matching SystemState, or
     *         {@link Optional#empty()} if no match exists
     */
    public static Optional<SystemState> fromString(final String s) {
        if (s == null) {
            return Optional.empty();
        }
        final String normalized = s.trim();
        for (final SystemState t : values()) {
            if (t.value.equalsIgnoreCase(normalized)) {
                return Optional.of(t);
            }
        }
        return Optional.empty();
    }

    /**
     * Like {@link #fromString(String)} but throws an
     * {@link IllegalArgumentException} if the string does not map to a valid
     * SystemState.
     *
     * @param s the string to parse, may be null
     * @return the matching SystemState
     * @throws IllegalArgumentException if no matching state exists
     */
    public static SystemState fromStringOrThrow(final String s) {
        return fromString(s).orElseThrow(() -> new IllegalArgumentException("Unknown SystemState: " + s));
    }

}
