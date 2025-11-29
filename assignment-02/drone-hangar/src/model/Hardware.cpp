#include "model/Hardware.h"
#include "config.h"

/**
 * @brief Initialize all hardware components
 * 
 * Creates and configures all hardware objects using pin definitions
 * from config.h. Must be called before using any hardware components.
 * 
 * Initializes:
 * - Button on BUTTON_PIN
 * - Three LEDs on LED1_PIN, LED2_PIN, LED3_PIN
 * - Motor on SERVO_PIN
 * - PIR sensor on PIR_PIN
 * - Sonar sensor on SONAR_TRIG_PIN and SONAR_ECHO_PIN with MAXTIME timeout
 * - Temperature sensor on TEMPERATURE_PIN
 * - LCD display at LCD_ADDR with LCD_COLS columns and LCD_ROWS rows
 */
void Hardware::init(void) {
    button = new Button(BUTTON_PIN, INPUT);
    led1 = new Led(LED1_PIN);
    led2 = new Led(LED2_PIN);
    led3 = new Led(LED3_PIN);
    motor = new Motor(SERVO_PIN);
    pir = new Pir(PIR_PIN);
    sonar = new Sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN, MAXTIME);
    tempSensor = new TMP36(TEMPERATURE_PIN);
    lcd = new Lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);
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
Lcd &Hardware::getLcd(void){
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
