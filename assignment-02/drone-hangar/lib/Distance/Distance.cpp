#include <Distance.h>

//
// Constants used for ultrasonic distance calculation
//
#define NO_OBJECTS     -1.0f    ///< Returned when no object is detected
#define DEFAULT_TEMP    20.0f   ///< Assumed ambient temperature in °C
#define SPEED_OF_SOUND (331.45f + 0.62f * DEFAULT_TEMP)  ///< Speed of sound (m/s)

#define US_TO_S(x)   ((x) / 1000000.0f)   ///< Microseconds → seconds
#define M_TO_CM(x)   ((x) * 100.0f)       ///< Meters → centimeters


/**
 * @brief Creates a Distance instance with given trigger and echo pins.
 */
Distance::Distance(uint8_t trigPin, uint8_t echoPin) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
}

/**
 * @brief Initializes the ultrasonic sensor pins.
 */
void Distance::begin() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

/**
 * @brief Measures distance using an ultrasonic pulse.
 *
 * @return Distance in centimeters, or NO_OBJECTS if no echo is detected.
 */
float Distance::read() {

    // Trigger pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);

    // Measure echo duration in microseconds
    float tUS = pulseIn(echoPin, HIGH);

    if (tUS <= 0) {
        return NO_OBJECTS;
    }

    // Convert to one-way travel time (seconds)
    float t = US_TO_S(tUS) / 2.0f;

    // Distance in meters and then centimeters
    float d_m = t * SPEED_OF_SOUND;
    float d_cm = M_TO_CM(d_m);

    return d_cm;
}
