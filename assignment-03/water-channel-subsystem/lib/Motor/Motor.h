#pragma once

#include <Arduino.h>
#include <ServoTimer2.h>

/**
 * @brief Servo motor controller class using ServoTimer2 library.
 * 
 * This class provides control for a servo motor, allowing it to be turned on/off
 * and positioned at specific angles between 0 and 180 degrees.
 */
class Motor final {
  private:
    uint8_t pin;
    ServoTimer2 motor;

  public:
    /**
     * @brief Constructs a Motor object for servo control.
     * 
     * @param pin The digital pin number where the servo is connected
     */
    explicit Motor(uint8_t pin);

    /**
     * @brief Attaches the servo to the pin, enabling control.
     */
    void on(void);

    /**
     * @brief Detaches the servo from the pin, disabling control.
     */
    void off(void);

    /**
     * @brief Sets the servo to a specific angular position.
     * 
     * @param angle The desired angle (0-180 degrees)
     */
    void setPosition(uint8_t angle);

    /**
     * @brief Destructor that ensures the servo is properly detached.
     * 
     * This destructor calls the off() method to detach the servo from the pin
     * when the Motor object is destroyed, preventing the servo from remaining
     * active and consuming power unnecessarily.
     */
    ~Motor();
};

