#include "core/Context.h"

/**
 * @file Context.cpp
 * @brief Implementation of the Context class.
 */

/**
 * @brief Constructs a new Context object and initializes it.
 */
Context::Context() {
    this->reset();
}

/**
 * @brief Resets all context states to default values.
 */
void Context::reset() {
    this->printDone();
    this->clearMsg();
    this->blockFlight();
    this->stopBlink();
    this->closeGate();
    this->printDone();
    this->doTakeOff();
    this->doLanding();
}

// ============ Print Status Setters ============

/**
 * @brief Set system print status to NORMAL and request printing.
 */
void Context::printNormal(void) {
    this->systemPrint = System::Print::NORMAL;
    this->print = true;
}

/**
 * @brief Set system print status to PREALARM and request printing.
 */
void Context::printPreAlarm(void) {
    this->systemPrint = System::Print::PREALARM;
    this->print = true;
}

/**
 * @brief Set system print status to ALARM and request printing.
 */
void Context::printAlarm(void) {
    this->systemPrint = System::Print::ALARM;
    this->print = true;
}

/**
 * @brief Set drone print status to INSIDE and request printing.
 */
void Context::printInside(void) {
    this->dronePrint = Drone::Print::INSIDE;
    this->print = true;
}

/**
 * @brief Set drone print status to TAKEOFF and request printing.
 */
void Context::printTakeOff(void) {
    this->dronePrint = Drone::Print::TAKEOFF;
    this->print = true;
}

/**
 * @brief Set drone print status to OUTSIDE and request printing.
 */
void Context::printOutside(void) {
    this->dronePrint = Drone::Print::OUTSIDE;
    this->print = true;
}

/**
 * @brief Set drone print status to LANDING and request printing.
 */
void Context::printLanding(void) {
    this->dronePrint = Drone::Print::LANDING;
    this->print = true;
}

/**
 * @brief Set both print statuses to DONE and disable printing.
 */
void Context::printDone(void) {
    this->systemPrint = System::Print::DONE;
    this->dronePrint = Drone::Print::DONE;
    this->print = false;
}

// ============ Message Management ============

/**
 * @brief Set pending message to TAKEOFF.
 */
void Context::setTakeOffMsg(void) {
    this->msg = TAKEOFF;
}

/**
 * @brief Set pending message to LANDING.
 */
void Context::setLandingMsg(void) {
    this->msg = LANDING;
}

/**
 * @brief Clear any pending message.
 */
void Context::clearMsg(void) {
    this->msg = NONE;
}

// ============ Flight Control ============

/**
 * @brief Allow flight operations.
 */
void Context::allowFlight(void) {
    this->flightAllowed = true;
}

/**
 * @brief Block flight operations.
 */
void Context::blockFlight(void) {
    this->flightAllowed = false;
}

// ============ Blink Control ============

/**
 * @brief Enable blinking.
 */
void Context::startBlink(void) {
    this->blinking = true;
}

/**
 * @brief Disable blinking.
 */
void Context::stopBlink(void) {
    this->blinking = false;
}

// ============ Gate Control ============

/**
 * @brief Open the gate.
 */
void Context::openGate(void) {
    this->opening = true;
}

/**
 * @brief Close the gate.
 */
void Context::closeGate(void) {
    this->opening = false;
}

// ============ Takeoff Operations ============

/**
 * @brief Start takeoff operation.
 */
void Context::doTakeOff(void) {
    this->takeoff = true;
    this->clearMsg();
}

/**
 * @brief Mark takeoff as completed and reset both operation flags.
 */
void Context::takeOffDone(void) {
    this->takeoff = false;
    this->landing = false;
}

// ============ Landing Operations ============

/**
 * @brief Start landing operation.
 */
void Context::doLanding(void) {
    this->landing = true;
    this->clearMsg();
}

/**
 * @brief Mark landing as completed and reset both operation flags.
 */
void Context::landingDone(void) {
    this->landing = false;
    this->takeoff = false;
}

// ============ State Getters ============

/**
 * @brief Get flight permission status.
 * @return Constant reference to flightAllowed flag.
 */
const bool &Context::isFlightAllowed(void) {
    return this->flightAllowed;
}

/**
 * @brief Get blinking status.
 * @return Constant reference to blinking flag.
 */
const bool &Context::shouldBlink(void) {
    return this->blinking;
}

/**
 * @brief Get gate opening status.
 * @return Constant reference to opening flag.
 */
const bool &Context::shouldOpen(void) {
    return this->opening;
}

/**
 * @brief Get print request status.
 * @return Constant reference to print flag.
 */
const bool &Context::shouldPrint(void) {
    return this->print;
}

/**
 * @brief Check if takeoff is in progress.
 * @return Constant reference to takeoff flag.
 */
const bool &Context::isTakeOffInProgress(void) {
    return this->takeoff;
}

/**
 * @brief Check if landing is in progress.
 * @return Constant reference to landing flag.
 */
const bool &Context::isLandingInProgress(void) {
    return this->landing;
}

// ============ Print Status Checkers ============

/**
 * @brief Check if NORMAL status should be printed.
 * @return true if systemPrint is NORMAL.
 */
bool Context::shouldPrintNormal(void) {
    return this->systemPrint == System::Print::NORMAL;
}

/**
 * @brief Check if PREALARM status should be printed.
 * @return true if systemPrint is PREALARM.
 */
bool Context::shouldPrintPreAlarm(void) {
    return this->systemPrint == System::Print::PREALARM;
}

/**
 * @brief Check if ALARM status should be printed.
 * @return true if systemPrint is ALARM.
 */
bool Context::shouldPrintAlarm(void) {
    return this->systemPrint == System::Print::ALARM;
}

/**
 * @brief Check if INSIDE status should be printed.
 * @return true if dronePrint is INSIDE.
 */
bool Context::shouldPrintInside(void) {
    return this->dronePrint == Drone::Print::INSIDE;
}

/**
 * @brief Check if TAKEOFF status should be printed.
 * @return true if dronePrint is TAKEOFF.
 */
bool Context::shouldPrintTakeOff(void) {
    return this->dronePrint == Drone::Print::TAKEOFF;
}

/**
 * @brief Check if OUTSIDE status should be printed.
 * @return true if dronePrint is OUTSIDE.
 */
bool Context::shouldPrintOutside(void) {
    return this->dronePrint == Drone::Print::OUTSIDE;
}

/**
 * @brief Check if LANDING status should be printed.
 * @return true if dronePrint is LANDING.
 */
bool Context::shouldPrintLanding(void) {
    return this->dronePrint == Drone::Print::LANDING;
}

// ============ Message Checkers ============

/**
 * @brief Check and consume TAKEOFF message.
 * @return true if TAKEOFF message was pending (consumes it).
 */
bool Context::isTakeOffMsg(void) {
    return this->msg == TAKEOFF;
}

/**
 * @brief Check and consume LANDING message.
 * @return true if LANDING message was pending (consumes it).
 */
bool Context::isLandingMsg(void) {
    return this->msg == LANDING;
}
