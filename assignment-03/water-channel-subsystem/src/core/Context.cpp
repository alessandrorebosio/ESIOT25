#include "core/Context.h"

/**
 * @brief Constructs a new Context object and initializes it.
 */
Context::Context() {
    this->reset();
}

void Context::reset(void) {
    this->setAutomatic();
}

void Context::setToPrint(System::Print value) {
    this->systemPrint = value;
    this->print = true;
}

void Context::printAutomatic(void) {
    this->setToPrint(System::Print::AUTOMATIC);
}

void Context::printManual(void) {
    this->setToPrint(System::Print::MANUAL);
}

void Context::clearPrint(void) {
    this->systemPrint = System::Print::NONE;
    this->print = false;
}

/**
 * @brief Get print request status.
 * @return Constant reference to print flag.
 */
const bool &Context::shouldPrint(void) {
    return this->print;
}

void Context::setAutomatic(void) {
    this->automatic = true;
}

void Context::setManual(void) {
    this->automatic = false;
}

bool Context::isAutomatic(void) {
    return this->automatic;
}
