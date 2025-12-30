#pragma once

#include <Arduino.h>

#include <Button.h>
#include <Lcd.h>
#include <Motor.h>
#include <Potentiometer.h>

/**
 * @brief Central hardware management class for the entire system
 *
 * This class serves as a facade that initializes and provides access to all
 * hardware components used in the system. It manages the lifecycle of all
 * hardware objects and provides a unified interface for accessing them.
 */
class Hardware final {
  private:
    Button *button;
    Motor *motor;
    Potentiometer *potentiometer;
    Lcd *lcd;

    uint8_t buttonPin;
    uint8_t motorPin;
    uint8_t potentiometerPin;
    uint8_t lcdAddr;
    uint8_t lcdCols;
    uint8_t lcdRows;

  public:
    /**
     * @brief Construct a Hardware object and store pin configuration
     */
    explicit Hardware(uint8_t buttonPin, uint8_t motorPin, uint8_t potentiometerPin, uint8_t lcdAddr, uint8_t lcdCols, uint8_t lcdRows);

    /**
     * @brief Initialize all hardware components.
     */
    void init();

    /**
     * @brief Get reference to button instance
     * @return Button& Reference to button object
     */
    Button &getButton(void);

    /**
     * @brief Get reference to motor for gate control
     * @return Motor& Reference to motor object
     */
    Motor &getMotor(void);

    Potentiometer &getPotentiometer(void);

    /**
     * @brief Get reference to LCD display
     * @return Lcd& Reference to LCD object
     */
    Lcd &getLcd(void);

    ~Hardware();
};