#pragma once

#include <Arduino.h>

class Led final {
  private:
	uint8_t pin;

  public:
	explicit Led(uint8_t pin);

	void on();

	void off();

	~Led() = default;
};
