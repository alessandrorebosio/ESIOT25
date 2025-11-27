#pragma once

#include <Arduino.h>
#include <ServoTimer2.h>

class Motor final {
  private:
	uint8_t pin;
	ServoTimer2 motor;

  public:
	explicit Motor(uint8_t pin);

	void on();

	void off();

	void setPosition(short angle);

	~Motor() = default;
};
