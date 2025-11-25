#include "model/Context.h"

Context::Context() {
    this->reset();
}

void Context::startOpening() {
    this->opening = true;
}

void Context::stopOpening() {
    this->opening = false;
}

bool Context::isOpening() {
    return this->opening;
}

void Context::reset() {
    this->stopOpening();
}
