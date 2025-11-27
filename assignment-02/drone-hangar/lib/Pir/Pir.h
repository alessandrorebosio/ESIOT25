#pragma once

#include <Arduino.h>

class Pir final {
  private:
	uint8_t pin;

  public:
	explicit Pir(uint8_t pin);

	bool isDetected();

	void calibrate();

	~Pir() = default;
};
