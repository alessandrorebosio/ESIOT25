#pragma once

#include <Arduino.h>

class TMP36 final {
  private:
	uint8_t pin;

  public:
	explicit TMP36(uint8_t pin);

	float readTemperature();

	~TMP36() = default;
};
