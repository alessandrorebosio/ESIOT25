#include "model/Hardware.h"

/**
 * @brief Initialize all hardware components.
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
 * Allocates memory for hardware objects and initializes them with
 * the configured pin settings. Must be called after constructor.
 */
void Hardware::init(void) {
    button = new Button(this->buttonPin, INPUT);
    motor = new Motor(this->motorPin);
    lcd = new Lcd(this->lcdAddr, this->lcdCols, this->lcdRows);
}

/**
 * @brief Check if the button is currently pressed.
 * Updates button state and returns current pressed status.
 * @return true if button is pressed, false otherwise.
 */
bool Hardware::isPressed(void) {
    this->button->sync();
    return this->button->isPressed();
}

/**
 * @brief Read the current potentiometer value.
 * @return Potentiometer reading (0-1023 typically).
 */
int Hardware::getPotValue(void) {
    return this->potentiometer->read();
}

/**
 * @brief Set the motor to a specific position.
 * @param value Target position value (implementation dependent).
 */
void Hardware::setMotorPosition(int value) {
    this->motor->setPosition(value);
}

/**
 * @brief Print a message on the LCD display.
 * @param y Row position (0-indexed) for the message.
 * @param msg Message string to display.
 */
void Hardware::printOnLcd(uint8_t y, String msg) {
    this->lcd->print(y, msg);
}

/**
 * @brief Destroy the Hardware object and clean up all components.
 * Deletes all allocated hardware objects to prevent memory leaks.
 * Automatically called when Hardware object goes out of scope.
 */
Hardware::~Hardware() {
    delete this->button;
    delete this->motor;
    delete this->potentiometer;
    delete this->lcd;
}
