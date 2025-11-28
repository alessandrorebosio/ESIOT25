#include "model/blink/HWBlink.h"

HWBlink::HWBlink(Led &led) : led(led) {
}

void HWBlink::turnOn() {
    this->led.on();
}

void HWBlink::turnOff() {
    this->led.off();
}
