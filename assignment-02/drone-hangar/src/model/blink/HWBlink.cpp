#include "model/blink/HWBlink.h"

/**
 * @brief Construct a new HWBlink object
 * @param led Reference to LED instance
 */
HWBlink::HWBlink(Led &led) : led(led) {
}

/**
 * @brief Turn on the LED
 */
void HWBlink::turnOn(void) {
    this->led.on();
}

/**
 * @brief Turn off the LED
 */
void HWBlink::turnOff(void) {
    this->led.off();
}
