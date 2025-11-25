#include "model/Context.h"

Context::Context() {
    this->reset();
}

void Context::startOpening() {
    this->opening = true;
}

void Context::startBlinking() {
    this->blinking = true;
}

void Context::stopOpening() {
    this->opening = false;
}

void Context::stopBlinking() {
    this->blinking = false;
}

bool Context::isOpening() {
    return this->opening;
}

bool Context::isBlinking() {
    return this->blinking;
}

void Context::reset() {
    this->stopOpening();
    this->stopOpening();
}
