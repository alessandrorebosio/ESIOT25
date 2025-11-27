#include "model/system/HWSystem.h"

HWSystem::HWSystem(Button &btn, Led &led, TMP36 &sensor) : button(btn), led(led), temp(sensor) {
}

bool HWSystem::isPressed() {
    return this->button.isPressed();
}

void HWSystem::turnOnLed() {
    this->led.on();
}

void HWSystem::turnOffLed() {
    this->led.off();
}

float HWSystem::temperature() {
    return this->temp.readTemperature();
}
