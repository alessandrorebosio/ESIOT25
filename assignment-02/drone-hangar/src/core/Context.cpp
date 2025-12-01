#include "core/Context.h"

Context::Context() {
    this->reset();
}

void Context::reset() {
    this->systemPrint = System::Print::DONE;
    this->dronePrint = Drone::Print::DONE;
    this->msg = NONE;
    this->blockFlight();
    this->stopBlink();
    this->closeGate();
    this->printDone();
    this->doTakeOff();
    this->doLanding();
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

void Context::setTakeOffMsg(void) {
    this->msg = TAKEOFF;
}

void Context::setLandingMsg(void) {
    this->msg = LANDING;
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

void Context::doTakeOff(void) {
    this->takeoff = true;
    this->msg = NONE;
}

void Context::takeOffDone(void) {
    this->takeoff = false;
    this->landing = false;
}

void Context::doLanding(void) {
    this->landing = true;
    this->msg = NONE;
}

void Context::landingDone(void) {
    this->landing = false;
    this->takeoff = false;
}

const bool &Context::isFlightAllowed(void) {
    return this->flightAllowed;
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

const bool &Context::isTakeOffInProgress(void) {
    return this->takeoff;
}

const bool &Context::isLandingInProgress(void) {
    return this->landing;
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

bool Context::isTakeOffMsg(void) {
    return this->msg == TAKEOFF;
}

bool Context::isLandingMsg(void) {
    return this->msg == LANDING;
}
