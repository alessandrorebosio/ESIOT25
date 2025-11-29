package it.unibo.iot.common.api;

import java.util.Objects;

public enum Messages {
    NORMAL("normal"),
    PREALARM("prealarm"),
    ALARM("alarm"),

    INSIDE("inside"),
    TAKEOFF("takeoff"),
    OUTSIDE("outside"),
    LANDING("landing"),

    NONE("");

    private final String value;

    Messages(final String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }

    public static Messages fromString(final String s) {
        Objects.requireNonNull(s, "The string cannot be null.");

        final String t = s.trim();
        for (final Messages m : values()) {
            if (m.name().equalsIgnoreCase(t) || m.value.equalsIgnoreCase(t)) {
                return m;
            }
        }
        return NONE;
    }
}
