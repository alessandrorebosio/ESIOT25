#pragma once

#include <Arduino.h>

#include <Button.h>
#include <Lcd.h>
#include <Motor.h>
#include <Potentiometer.h>

/**
 * @brief Central hardware management class for the entire system.
 *
 * This class serves as a facade that initializes and provides access to all
 * hardware components used in the system. It manages the lifecycle of all
 * hardware objects and provides a unified interface for accessing them.
 * The class follows the RAII (Resource Acquisition Is Initialization) pattern
 * to ensure proper resource management.
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
     * @brief Construct a Hardware object and store pin configuration.
     * @param buttonPin Digital pin connected to the button.
     * @param motorPin PWM pin connected to the motor.
     * @param potentiometerPin Analog pin connected to the potentiometer.
     * @param lcdAddr I2C address of the LCD display.
     * @param lcdCols Number of columns in the LCD display.
     * @param lcdRows Number of rows in the LCD display.
     */
    explicit Hardware(uint8_t buttonPin, uint8_t motorPin, uint8_t potentiometerPin, uint8_t lcdAddr, uint8_t lcdCols, uint8_t lcdRows);

    /**
     * @brief Initialize all hardware components.
     * Must be called before using any hardware components. Allocates memory
     * for hardware objects and sets up their initial state.
     */
    void init(void);

    /**
     * @brief Check if the button is currently pressed.
     * @return true if button is pressed, false otherwise.
     */
    bool isPressed(void);

    /**
     * @brief Read the current potentiometer value.
     * @return Potentiometer reading (0-1023 typically).
     */
    int getPotValue(void);

    /**
     * @brief Set the motor to a specific position.
     * @param value Target position value (implementation dependent).
     */
    void setMotorPosition(int value);

    /**
     * @brief Print a message on the LCD display.
     * @param y Row position (0-indexed) for the message.
     * @param msg Message string to display.
     */
    void printOnLcd(uint8_t y, String msg);

    /**
     * @brief Print "MANUAL" on the LCD display.
     */
    void printManual();

    /**
     * @brief Print "AUTOMATIC" on the LCD display.
     */
    void printAutomatic();

    /**
     * @brief Print "UNCONNECTED" on the LCD display.
     */
    void printUnconnected();

    /**
     * @brief Print the percentual of valve opening on the LCD display.
     */
    void printValveValue(uint8_t value);

    /**
     * @brief Destroy the Hardware object and clean up all components.
     * Deletes all allocated hardware objects to prevent memory leaks.
     * Automatically called when Hardware object goes out of scope.
     */
    ~Hardware();
};