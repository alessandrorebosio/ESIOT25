#include "core/Context.h"

Context::Context() {
    this->reset();
}

void Context::reset() {
    this->stopBlink();
    this->closeGate();
    this->printDone();
}

void Context::printNormal(void) {
    this->systemPrint = System::Print::NORMAL;
    this->print = true;
}

void Context::printPreAlarm(void) {
    this->systemPrint = System::Print::PREALARM;
    this->print = true;
}

void Context::printAlarm(void) {
    this->systemPrint = System::Print::ALARM;
    this->print = true;
}

void Context::printInside(void) {
    this->dronePrint = Drone::Print::INSIDE;
    this->print = true;
}

void Context::printTakeOff(void) {
    this->dronePrint = Drone::Print::TAKEOFF;
    this->print = true;
}

void Context::printOutside(void) {
    this->dronePrint = Drone::Print::OUTSIDE;
    this->print = true;
}

void Context::printLanding(void) {
    this->dronePrint = Drone::Print::LANDING;
    this->print = true;
}

void Context::printDone(void) {
    this->systemPrint = System::Print::DONE;
    this->dronePrint = Drone::Print::DONE;
    this->print = false;
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

const bool &Context::shouldBlink(void) {
    return this->blinking;
}

const bool &Context::shouldOpen(void) {
    return this->opening;
}

const bool &Context::shouldPrint(void) {
    return this->print;
}

bool Context::shouldPrintNormal(void) {
    return this->systemPrint == System::Print::NORMAL;
}

bool Context::shouldPrintPreAlarm(void) {
    return this->systemPrint == System::Print::PREALARM;
}

bool Context::shouldPrintAlarm(void) {
    return this->systemPrint == System::Print::ALARM;
}

bool Context::shouldPrintInside(void) {
    return this->dronePrint == Drone::Print::INSIDE;
}

bool Context::shouldPrintTakeOff(void) {
    return this->dronePrint == Drone::Print::TAKEOFF;
}

bool Context::shouldPrintOutside(void) {
    return this->dronePrint == Drone::Print::OUTSIDE;
}

bool Context::shouldPrintLanding(void) {
    return this->dronePrint == Drone::Print::LANDING;
}
