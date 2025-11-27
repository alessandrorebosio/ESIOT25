#include "core/Context.h"

Context::Context() {
	this->reset();
}

void Context::startBlink() {
	this->blinking = true;
}

void Context::stopBlink() {
	this->blinking = false;
}

bool &Context::shouldBlink() {
	return this->blinking;
}

void Context::reset() {
	this->stopBlink();
}
