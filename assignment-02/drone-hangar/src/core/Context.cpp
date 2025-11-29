#include "core/Context.h"

Context::Context() {
    this->reset();
}

void Context::reset() {
    this->stopBlink();
    this->closeGate();
    this->startMeasuring();
    this->printDone();
}

void Context::printNormal(void) {
    this->systemPrint = Context::NORMAL;
}

void Context::printPreAlarm(void) {
    this->systemPrint = Context::PREALARM;
}

void Context::printAlarm(void) {
    this->systemPrint = Context::ALARM;
}

void Context::printDone(void) {
    this->systemPrint = Context::DONE;
}

void Context::allowFlight(void) {
    this->flightAllowed = true;
}

void Context::blockFlight(void) {
    this->flightAllowed = false;
}

void Context::startBlink(void) {
    this->blinking = true;
}

void Context::stopBlink(void) {
    this->blinking = false;
}

void Context::openGate(void) {
    this->opening = true;
}

void Context::closeGate(void) {
    this->opening = false;
}

void Context::startMeasuring(void) {
    this->measuring = true;
}

void Context::stopMeasuring(void) {
    this->measuring = false;
}

const bool &Context::shouldBlink(void) const {
    return this->blinking;
}

const bool &Context::shouldOpen(void) const {
    return this->opening;
}

const bool &Context::shouldMeasure(void) const {
    return this->measuring;
}

bool Context::shouldListen(void) {
    return true;
}

bool Context::shouldPrint(void) {
    return this->systemPrint != Context::DONE;
}

bool Context::shouldPrintNormal(void) {
    return this->systemPrint == Context::NORMAL;
}

bool Context::shouldPrintPreAlarm(void) {
    return this->systemPrint == Context::PREALARM;
}

bool Context::shouldPrintAlarm(void) {
    return this->systemPrint == Context::ALARM;
}
