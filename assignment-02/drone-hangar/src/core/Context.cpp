#include "core/Context.h"

Context::Context() {
    this->reset();
}

void Context::allowFlight() {
    this->flightAllowed = true;
}

void Context::blockFlight() {
    this->flightAllowed = false;
}

void Context::startBlink() {
    this->blinking = true;
}

void Context::stopBlink() {
    this->blinking = false;
}

const bool &Context::isFlightAllowed() const {
    return this->flightAllowed;
}

const bool &Context::shouldBlink() const {
    return this->blinking;
}

void Context::reset() {
    this->stopBlink();
    this->blockFlight();
}
