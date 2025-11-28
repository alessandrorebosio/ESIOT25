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

void Context::dotTakeOff() {
    this->takeOff = true;
    this->landing = false;
}
void Context::doLanding() {
    this->landing = true;
    this->takeOff = false;
}

const bool &Context::isFlightAllowed() const {
    return this->flightAllowed;
}

const bool &Context::shouldBlink() const {
    return this->blinking;
}

bool Context::isOperationDone() const {
    return !(this->landing || this->takeOff);
}

bool Context::isTakeOff() const {
    return this->takeOff;
}
bool Context::isLanding() const {
    return this->landing;
}

void Context::reset() {
    this->stopBlink();
    this->blockFlight();
}
