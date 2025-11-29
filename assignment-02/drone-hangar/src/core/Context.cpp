#include "core/Context.h"

Context::Context() {
    this->reset();
}

void Context::reset() {
    this->stopBlink();
    this->closeGate();
    this->printDone();
}

void Context::printNormal() {
    this->systemPrint = Context::NORMAL;
}

void Context::printPreAlarm() {
    this->systemPrint = Context::PREALARM;
}

void Context::printAlarm() {
    this->systemPrint = Context::ALARM;
}

void Context::printDone() {
    this->systemPrint = Context::DONE;
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

const bool &Context::shouldBlink() const {
    return this->blinking;
}

const bool &Context::shouldOpen() const {
    return this->opening;
}

bool Context::shouldPrint() {
    return this->systemPrint != Context::DONE;
}

bool Context::shouldPrintNormal() {
    return this->systemPrint == Context::NORMAL;
}
bool Context::shouldPrintPreAlarm() {
    return this->systemPrint == Context::PREALARM;
}
bool Context::shouldPrintAlarm() {
    return this->systemPrint == Context::ALARM;
}
