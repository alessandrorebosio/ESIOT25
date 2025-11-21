package it.unibo.iot.common;

import java.util.Optional;

public enum SystemState {
    NORMAL("normal"),
    PREALARM("prealarm"),
    ALARM("alarm");

    private final String value;

    SystemState(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return value;
    }

    /**
     * Restituisce un Optional con l'enum corrispondente alla stringa
     * (case-insensitive),
     * o Optional.empty() se non esiste corrispondenza.
     */
    public static Optional<SystemState> fromString(String s) {
        if (s == null)
            return Optional.empty();
        String normalized = s.trim();
        for (SystemState t : values()) {
            if (t.value.equalsIgnoreCase(normalized))
                return Optional.of(t);
        }
        return Optional.empty();
    }

    /**
     * Come fromString ma lancia IllegalArgumentException se la stringa non
     * corrisponde.
     */
    public static SystemState fromStringOrThrow(String s) {
        return fromString(s).orElseThrow(() -> new IllegalArgumentException("Unknown AppStateType: " + s));
    }
}