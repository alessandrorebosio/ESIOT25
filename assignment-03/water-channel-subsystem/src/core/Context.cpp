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

void Context::setAutomatic(void) {
    this->automatic = true;
}

void Context::setManual(void) {
    this->automatic = false;
}

bool Context::isAutomatic(void) {
    return this->automatic;
}
