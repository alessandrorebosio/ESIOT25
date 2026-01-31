#include "core/Context.h"

/**
 * @brief Constructs a new Context object and initializes it.
 */
Context::Context() {
    this->reset();
}

void Context::reset(void) {
    this->setAutomatic();
    this->printDone();
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

void Context::printDone(void) {
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

/**
 * @brief Check if AUTOMATIC status should be printed.
 * @return true if systemPrint is AUTOMATIC.
 */
bool Context::shouldPrintAutomatic(void) {
    return this->systemPrint == System::Print::AUTOMATIC;
}

/**
 * @brief Check if MANUAL status should be printed.
 * @return true if systemPrint is MANUAL.
 */
bool Context::shouldPrintManual(void) {
    return this->systemPrint == System::Print::MANUAL;
}

void Context::setValveOpening(float value) { 
    this->valveOpening = value; 
}

float Context::getValveOpening(void) const { 
    return this->valveOpening; 
}
