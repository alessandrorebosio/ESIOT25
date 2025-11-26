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

void Context::startBlink() {
    this->blinking = true;
}

void Context::stopBlink() {
    this->blinking = false;
}

void Context::open() {
    this->opening = true;
}

void Context::close() {
    this->opening = false;
}

bool Context::isFlightOperationAllowed() const {
    return this->flightOperation;
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
    this->close();
}
