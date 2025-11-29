#include "model/system/HWSystem.h"

/**
 * @brief Construct a new HWSystem object
 * @param btn Reference to button instance
 * @param led1 Reference to first LED instance
 * @param led2 Reference to second LED instance
 * @param temp Reference to temperature sensor instance
 */
HWSystem::HWSystem(Button &btn, Led &led1, Led &led2, TMP36 &temp) 
    : button(btn), led1(led1), led2(led2), temp(temp) {
}

/**
 * @brief Check if button is pressed
 * @return true if button is pressed, false otherwise
 */
bool HWSystem::isPressed(void) {
    return this->button.isPressed();
}

/**
 * @brief Turn on the first LED (normal/pre-alarm indicator)
 */
void HWSystem::turnOnLed1(void) {
    this->led1.on();
}

/**
 * @brief Turn off the first LED
 */
void HWSystem::turnOffLed1(void) {
    this->led1.off();
}

/**
 * @brief Turn on the second LED (alarm indicator)
 */
void HWSystem::turnOnLed2(void) {
    this->led2.on();
}

/**
 * @brief Turn off the second LED
 */
void HWSystem::turnOffLed2(void) {
    this->led2.off();
}

/**
 * @brief Read current temperature from sensor
 * @return float Current temperature in degrees Celsius
 */
float HWSystem::temperature(void) {
    return this->temp.readTemperature();
}
