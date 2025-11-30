package it.unibo.iot.common.api;

import java.util.Objects;

/**
 * Enumeration representing various system messages and states for IoT
 * applications.
 * 
 * <p>
 * This enum provides a centralized definition of message types used throughout
 * the system, including temperature monitoring states and flight operation
 * commands.
 * </p>
 * 
 * <p>
 * Each message has both an enum name and a string value for flexible parsing
 * and serialization.
 * </p>
 * 
 * @author System Author
 * @version 1.0
 */
public enum Messages {
    /**
     * Temperature monitoring system is operating within normal parameters.
     */
    NORMAL("normal"),

    /**
     * Temperature monitoring system has entered pre-alarm state.
     */
    PREALARM("prealarm"),

    /**
     * Temperature monitoring system has entered alarm state.
     */
    ALARM("alarm"),

    /**
     * Object is detected inside the monitored area.
     */
    INSIDE("inside"),

    /**
     * Flight system is executing takeoff procedure.
     */
    TAKEOFF("takeoff"),

    /**
     * Object has moved outside the monitored area.
     */
    OUTSIDE("outside"),

    /**
     * Flight system is executing landing procedure.
     */
    LANDING("landing"),

    /**
     * Represents no message or unknown message type.
     */
    NONE("");

    /** The string value associated with this message. */
    private final String value;

    /**
     * Constructs a new Messages enum constant with the specified string value.
     * 
     * @param value the string representation of this message
     */
    Messages(final String value) {
        this.value = value;
    }

    /**
     * Returns the string value associated with this message.
     * 
     * @return the string value of this message, never null
     */
    public String getValue() {
        return value;
    }

    /**
     * Converts a string to the corresponding Messages enum value.
     * 
     * <p>
     * The conversion is case-insensitive and matches against both the enum name
     * and the string value. Leading and trailing whitespace is ignored.
     * </p>
     * 
     * <p>
     * Examples of valid inputs:
     * <ul>
     * <li>"normal" or "NORMAL" → Messages.NORMAL</li>
     * <li>"prealarm" or "PREALARM" → Messages.PREALARM</li>
     * <li>"takeoff" or "TAKEOFF" → Messages.TAKEOFF</li>
     * </ul>
     * </p>
     * 
     * @param s the string to convert, must not be null
     * @return the corresponding Messages enum value, or Messages.NONE if no match
     *         is found
     * @throws NullPointerException if the input string is null
     */
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
