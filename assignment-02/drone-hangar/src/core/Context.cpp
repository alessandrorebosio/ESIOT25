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
    this->measuring = false;
}

void Context::doLanding() {
    this->landing = true;
    this->takeOff = false;
}

void Context::startMeasuring() {
    this->measuring = true;
    this->takeOff = false;
    this->landing = false;
}

void Context::takeOffDone() {
    this->takeOff = false;
}

void Context::landingDone() {
    this->landing = false;
}

void Context::stopMeasuring() {
    this->measuring = false;
}

const bool &Context::isFlightAllowed() const {
    return this->flightAllowed;
}

const bool &Context::shouldBlink() const {
    return this->blinking;
}

bool Context::shouldMeasure() {
    return this->measuring;
}

const bool &Context::shouldOpen() const {
    return this->opening;
}

bool Context::isOperationDone() {
    return !(this->landing || this->takeOff);
}

const bool &Context::isTakeOff() const {
    return this->takeOff;
}

const bool &Context::isLanding() const {
    return this->landing;
}

void Context::reset() {
    this->startMeasuring();
    this->stopBlink();
    this->closeGate();
    this->blockFlight();
    this->doTakeOff();
    this->takeOffDone();
}
