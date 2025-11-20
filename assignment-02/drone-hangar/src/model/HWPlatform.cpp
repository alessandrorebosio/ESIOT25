#include "model/HWPlatform.h"

#include <Button.h>
#include <Led.h>
#include <Pir.h>
#include <ServoMotor.h>
#include <Sonar.h>
#include <TempSensorTMP36.h>

#include "config.h"

HWPlatform::HWPlatform() {}

void HWPlatform::init() {
    button = new Button(BUTTON_PIN);
    led1 = new Led(LED1_PIN);
    led2 = new Led(LED2_PIN);
    led3 = new Led(LED3_PIN);
    pir = new Pir(PIR_PIN);
    motor = new ServoMotor(SERVO_PIN);
    sonar = new Sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN, MAXTIME);
    tempSensor = new TempSensorTMP36(TEMPERATURE_PIN);
}