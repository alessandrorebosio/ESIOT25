#include <Arduino.h>
#include <Button.h>
#include <Distance.h>
#include <Lcd.h>
#include <Led.h>
#include <MyServo.h>
#include <Presence.h>
#include <Temperature.h>
#include <Timer.h>

#include "config.h"
#include "logic.h"

Distance sonar(SONAR_ECHO_PIN, SONAR_TRIG_PIN);
Temperature temp(TEMP_PIN);
MyServo servo(SERVO_PIN);
Button button(BTN_PIN);
Presence pir(PIR_PIN);

Led l1(L1_LED);
Led l2(L2_LED);
Led l3(L3_LED);

Timer t0;
Timer t1;

Logic logic;

void setup()
{
    Serial.begin(BAUD);
    button.begin();
    sonar.begin();
    temp.begin();
    // pir.begin();
    l1.begin();
    l2.begin();
    l3.begin();
    servo.on();
}

void loop()
{
    Serial.println(temp.read());
    if (temp.equals(20) == 1)
    {
        Serial.println("ciao");
    }
    else if (temp.equals(20) == -1)
    {
        Serial.println("bye");
    }
}
