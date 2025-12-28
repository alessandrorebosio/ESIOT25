#include "Sonar.h"

#define NO_OBJ_DETECTED -1.0f  ///< Return value when no object is detected
#define DELAY1 2               ///< Initial delay in microseconds
#define DELAY2 10              ///< Trigger pulse duration in microseconds

/**
 * @brief Constructs a Sonar object and initializes the pins.
 * 
 * @param trigPin The trigger pin number
 * @param echoPin The echo pin number
 * @param maxTime The maximum time to wait for echo in microseconds
 */
Sonar::Sonar(uint8_t trigPin, uint8_t echoPin, unsigned long maxTime)
    : trigPin(trigPin), echoPin(echoPin), temperature(20.0f), timeOut(maxTime) {
    pinMode(this->trigPin, OUTPUT);
    pinMode(this->echoPin, INPUT);

    digitalWrite(this->trigPin, LOW);
}

/**
 * @brief Sets the temperature for sound speed compensation.
 * 
 * @param temperature The temperature in degrees Celsius
 */
void Sonar::setTemperature(const float temperature) {
    this->temperature = temperature;
}

/**
 * @brief Calculates the speed of sound based on current temperature.
 * 
 * Uses the formula: speed = 331.5 + 0.6 * temperature
 * 
 * @return The speed of sound in meters per second
 */
float Sonar::getSoundSpeed() {
    return 331.5 + 0.6 * this->temperature;
}

/**
 * @brief Measures and returns the distance to the nearest object.
 * 
 * Sends an ultrasonic pulse and measures the time for the echo to return.
 * Converts the time to distance using temperature-compensated sound speed.
 * 
 * @return Distance in centimeters, or NO_OBJ_DETECTED if no object is detected
 */
float Sonar::readDistance() {
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(DELAY1);
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(DELAY2);
    digitalWrite(this->trigPin, LOW);

    unsigned long tUS = pulseIn(this->echoPin, HIGH, this->timeOut);
    if (tUS == 0UL) {
        return NO_OBJ_DETECTED;
    }

    // Convert microseconds to seconds, divide by 2 (round-trip), multiply by
    // speed (m/s) and convert to cm
    return tUS * 1e-6f * 0.5f * this->getSoundSpeed() * 100.0f;
}
