#include "TMP36.h"

#define MV_PER_C 10.0    ///< Millivolts per degree Celsius for TMP36
#define ADC_RES 1024     ///< ADC resolution (10-bit)
#define SAMPLES 10       ///< Number of samples for averaging
#define OFFSET 0.5       ///< Voltage offset at 0°C in volts
#define VREF 5.0         ///< Reference voltage for ADC

/**
 * @brief Constructs a TMP36 object and initializes the pin as INPUT.
 * 
 * @param pin The analog pin number where the TMP36 sensor is connected
 */
TMP36::TMP36(const uint8_t pin) : pin(pin) {
    pinMode(this->pin, INPUT);
}

/**
 * @brief Reads the current temperature in Celsius.
 * 
 * This method takes multiple samples, averages them, and converts the
 * analog reading to temperature in degrees Celsius using the TMP36
 * conversion formula.
 * 
 * @return The temperature in degrees Celsius
 */
float TMP36::readTemperature() {
    float sum = 0;
    for (uint8_t i = 0; i < SAMPLES; i++) {
        int adcValue = analogRead(this->pin);
        float voltage = (adcValue * VREF) / ADC_RES;
        sum += (voltage - OFFSET) * (1000.0 / MV_PER_C);
        delay(1);
    }

    return sum / SAMPLES;
}
