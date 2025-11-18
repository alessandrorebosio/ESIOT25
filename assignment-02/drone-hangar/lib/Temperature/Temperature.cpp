#include <Temperature.h>

//
// Constants for TMP36 conversion
//
#define ADC_TO_VOLT  0.00488f   // 5V / 1024 steps
#define TMP36_OFFSET 0.5f       // 500 mV offset at 0°C
#define TMP36_SCALE  0.01f      // 10 mV/°C


/**
 * @brief Constructs a Temperature reader for the given analog pin.
 * @param pin Analog pin where the TMP36 sensor is connected.
 */
Temperature::Temperature(uint8_t pin) { this->pin = pin; }

/**
 * @brief Initializes the sensor pin.
 */
void Temperature::begin() { pinMode(pin, INPUT); }

/**
 * @brief Reads the temperature in Celsius from the TMP36 sensor.
 *
 * The calculation follows the TMP36 characteristics:
 *   Vout = (Temp * 0.01) + 0.5
 *
 * @return Temperature in °C.
 */
float Temperature::read() {
    int raw = analogRead(pin);

    float voltage = raw * ADC_TO_VOLT;

    float tempC = (voltage - TMP36_OFFSET) / TMP36_SCALE;

    return tempC;
}
