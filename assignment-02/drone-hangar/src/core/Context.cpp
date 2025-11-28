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

void Context::openGate() {
    this->opening = true;
}

void Context::closeGate() {
    this->opening = false;
    }

void Context::doTakeOff() {
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

const bool &Context::shouldOpen() const {
    return this->opening;
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
