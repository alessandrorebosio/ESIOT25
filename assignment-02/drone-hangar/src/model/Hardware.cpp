#include "model/Hardware.h"

/**
 * @brief Initialize all hardware components
 *
 * Creates and configures all hardware objects using pin definitions
 * from config.h. Must be called before using any hardware components.
 */
Hardware::Hardware(uint8_t btnPin, uint8_t l1Pin, uint8_t l2Pin, uint8_t l3Pin, uint8_t servoPin, uint8_t pirPin, uint8_t sonarTrigPin,
                   uint8_t sonarEchoPin, unsigned long maxTime, uint8_t tmpPin, uint8_t lcdAddr, uint8_t lcdCols, uint8_t lcdRows)
    : button(nullptr), led1(nullptr), led2(nullptr), led3(nullptr), motor(nullptr), pir(nullptr), sonar(nullptr), tempSensor(nullptr), lcd(nullptr),
      btnPin(btnPin), l1Pin(l1Pin), l2Pin(l2Pin), l3Pin(l3Pin), servoPin(servoPin), pirPin(pirPin), sonarTrigPin(sonarTrigPin),
      sonarEchoPin(sonarEchoPin), maxTime(maxTime), tmpPin(tmpPin), lcdAddr(lcdAddr), lcdCols(lcdCols), lcdRows(lcdRows) {
}

/**
 * @brief Initialize all hardware components.
 */
void Hardware::init() {
    button = new Button(this->btnPin, INPUT);
    led1 = new Led(this->l1Pin);
    led2 = new Led(this->l2Pin);
    led3 = new Led(this->l3Pin);
    motor = new Motor(this->servoPin);
    pir = new Pir(this->pirPin);
    sonar = new Sonar(this->sonarTrigPin, this->sonarEchoPin, this->maxTime);
    tempSensor = new TMP36(this->tmpPin);
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
 * @brief Get reference to first LED
 * @return Led& Reference to LED1 object
 */
Led &Hardware::getLed1(void) {
    return *this->led1;
}

/**
 * @brief Get reference to second LED
 * @return Led& Reference to LED2 object
 */
Led &Hardware::getLed2(void) {
    return *this->led2;
}

/**
 * @brief Get reference to third LED
 * @return Led& Reference to LED3 object
 */
Led &Hardware::getLed3(void) {
    return *this->led3;
}

/**
 * @brief Get reference to PIR motion sensor
 * @return Pir& Reference to PIR object
 */
Pir &Hardware::getPir(void) {
    return *this->pir;
}

/**
 * @brief Get reference to ultrasonic distance sensor
 * @return Sonar& Reference to sonar object
 */
Sonar &Hardware::getSonar(void) {
    return *this->sonar;
}

/**
 * @brief Get reference to temperature sensor
 * @return TMP36& Reference to temperature sensor object
 */
TMP36 &Hardware::getTempSensor(void) {
    return *this->tempSensor;
}

/**
 * @brief Get reference to motor for gate control
 * @return Motor& Reference to motor object
 */
Motor &Hardware::getMotor(void) {
    return *this->motor;
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
    delete this->led1;
    delete this->led2;
    delete this->led3;
    delete this->motor;
    delete this->pir;
    delete this->sonar;
    delete this->tempSensor;
    delete this->lcd;
}
