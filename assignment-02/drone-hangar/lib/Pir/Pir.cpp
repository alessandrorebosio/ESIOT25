#include "Pir.h"

#define CALIBRATION_TIME 10000

/**
 * @brief Constructs a Pir object and initializes the pin as INPUT.
 *
 * @param pin The digital pin number where the PIR sensor is connected
 */
Pir::Pir(const uint8_t pin) : pin(pin) {
    pinMode(this->pin, INPUT);
}

/**
 * @brief Checks if motion is detected by the PIR sensor.
 *
 * @return true if motion is detected, false otherwise
 */
bool Pir::isDetected() {
    return digitalRead(this->pin);
}

/**
 * @brief Calibrates the PIR sensor for stable operation.
 *
 * This method blocks for CALIBRATION_TIME (10 seconds) to allow the PIR sensor
 * to stabilize and establish a proper baseline reading for motion detection.
 * This should be called during the setup phase of your application.
 */
void Pir::calibrate() {
    delay(CALIBRATION_TIME);
}
