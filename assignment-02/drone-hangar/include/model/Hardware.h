#pragma once

#include <Arduino.h>

#include <Button.h>
#include <Lcd.h>
#include <Led.h>
#include <Motor.h>
#include <Pir.h>
#include <Sonar.h>
#include <TMP36.h>

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
    Led *led1;
    Led *led2;
    Led *led3;
    Motor *motor;
    Pir *pir;
    Sonar *sonar;
    TMP36 *tempSensor;
    Lcd *lcd;

    uint8_t btnPin;
    uint8_t l1Pin;
    uint8_t l2Pin;
    uint8_t l3Pin;
    uint8_t servoPin;
    uint8_t pirPin;
    uint8_t sonarTrigPin;
    uint8_t sonarEchoPin;
    int maxTime;
    uint8_t tmpPin;
    uint8_t lcdAddr;
    uint8_t lcdCols;
    uint8_t lcdRows;

  public:
    /**
     * @brief Construct a Hardware object and store pin configuration
     */
    Hardware(uint8_t btnPin, uint8_t l1Pin, uint8_t l2Pin, uint8_t l3Pin, uint8_t servoPin, uint8_t pirPin, uint8_t sonarTrigPin,
             uint8_t sonarEchoPin, int maxTime, uint8_t tmpPin, uint8_t lcdAddr, uint8_t lcdCols, uint8_t lcdRows);

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
     * @brief Get reference to first LED
     * @return Led& Reference to LED1 object
     */
    Led &getLed1(void);

    /**
     * @brief Get reference to second LED
     * @return Led& Reference to LED2 object
     */
    Led &getLed2(void);

    /**
     * @brief Get reference to third LED
     * @return Led& Reference to LED3 object
     */
    Led &getLed3(void);

    /**
     * @brief Get reference to PIR motion sensor
     * @return Pir& Reference to PIR object
     */
    Pir &getPir(void);

    /**
     * @brief Get reference to ultrasonic distance sensor
     * @return Sonar& Reference to sonar object
     */
    Sonar &getSonar(void);

    /**
     * @brief Get reference to temperature sensor
     * @return TMP36& Reference to temperature sensor object
     */
    TMP36 &getTempSensor(void);

    /**
     * @brief Get reference to motor for gate control
     * @return Motor& Reference to motor object
     */
    Motor &getMotor(void);

    /**
     * @brief Get reference to LCD display
     * @return Lcd& Reference to LCD object
     */
    Lcd &getLcd(void);

    /**
     * @brief Destroy the Hardware object and clean up all components
     *
     * Deletes all allocated hardware objects to prevent memory leaks.
     * Automatically called when Hardware object goes out of scope.
     */
    ~Hardware();
};
