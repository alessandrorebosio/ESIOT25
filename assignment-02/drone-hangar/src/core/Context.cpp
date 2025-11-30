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
}

void Context::printPreAlarm(void) {
    this->systemPrint = System::Print::PREALARM;
}

void Context::printAlarm(void) {
    this->systemPrint = System::Print::ALARM;
}

void Context::printInside(void) {
    this->dronePrint = Drone::Print::INSIDE;
}

void Context::printTakeOff(void) {
    this->dronePrint = Drone::Print::TAKEOFF;
}

void Context::printOutside(void) {
    this->dronePrint = Drone::Print::OUTSIDE;
}

void Context::printLanding(void) {
    this->dronePrint = Drone::Print::LANDING;
}

void Context::printDone(void) {
    this->systemPrint = System::Print::DONE;
    this->dronePrint = Drone::Print::DONE;
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

Predicate Context::shouldBlink(void) {
    return this->blinking;
}

Predicate Context::shouldOpen(void) {
    return this->opening;
}

Predicate Context::shouldPrint(void) {
    return this->systemPrint != System::Print::DONE || this->dronePrint != Drone::Print::DONE;
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