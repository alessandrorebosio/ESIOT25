#include "core/Context.h"

Context::Context() {
    this->reset();
}

void Context::allowFlightOperation() {
    this->flightOperation = true;
}

void Context::blockFlightOperation() {
    this->flightOperation = false;
}

void Context::startMeasuring() {
    this->measuring = true;
}

void Context::stopMeasuring() {
    this->measuring = false;
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

bool Context::isFlightOperationAllowed() const {
    return this->flightOperation;
}

bool Context::isMeasured() const {
    return !this->measuring;
}

bool Context::shouldOpen() const {
    return this->opening;
}

bool Context::shouldBlink() const {
    return this->blinking;
}

void Context::reset() {
    this->blockFlightOperation();
    this->stopBlink();
    this->closeGate();
}
