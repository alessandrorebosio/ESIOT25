#include "model/Hardware.h"

/**
 * @brief Initialize all hardware components
 *
 * Creates and configures all hardware objects using pin definitions
 * from config.h. Must be called before using any hardware components.
 */
Hardware::Hardware(uint8_t buttonPin, uint8_t motorPin, uint8_t potentiometerPin, uint8_t lcdAddr, uint8_t lcdCols, uint8_t lcdRows)
    : button(nullptr), motor(nullptr), potentiometer(nullptr), lcd(nullptr), buttonPin(buttonPin), motorPin(motorPin), lcdAddr(lcdAddr),
      lcdCols(lcdCols), lcdRows(lcdRows) {
}

/**
 * @brief Initialize all hardware components.
 */
void Hardware::init() {
    button = new Button(this->buttonPin, INPUT);
    motor = new Motor(this->motorPin);
    lcd = new Lcd(this->lcdAddr, this->lcdCols, this->lcdRows);
}

/**
 * @brief Get reference to button instance
 * @return Button& Reference to button object
 */
Button &Hardware::getButton(void) {
    return *this->button;
}

/**
 * @brief Get reference to motor for gate control
 * @return Motor& Reference to motor object
 */
Motor &Hardware::getMotor(void) {
    return *this->motor;
}

/**
 * @brief Get reference to potentiometer instance
 * @return Potentiometer& Reference to pot object
 */
Potentiometer &Hardware::getPotentiometer(void) {
    return *this->potentiometer;
}

/**
 * @brief Get reference to LCD display
 * @return Lcd& Reference to LCD object
 */
Lcd &Hardware::getLcd(void) {
    return *this->lcd;
}

/**
 * @brief Destroy the Hardware object and clean up all components
 *
 * Deletes all allocated hardware objects to prevent memory leaks.
 * Automatically called when Hardware object goes out of scope.
 */
Hardware::~Hardware() {
    delete this->button;
    delete this->motor;
    delete this->potentiometer;
    delete this->lcd;
}
