#pragma once

#include <Arduino.h>

class Button final {
  private:
	uint8_t pin;

  public:
	explicit Button(uint8_t pin, uint8_t mode);

	bool isPressed();

	~Button() = default;
};
