#pragma once

#include <Pir.h>
#include <Sonar.h>
#include <TMP36.h>
#include <Lcd.h>

class HWFlight final {
  private:
    Pir &pir;
    Sonar &sonar;
    TMP36 &temp;
    Lcd &lcd;

  public:
    explicit HWFlight(Pir &pir, Sonar &sonar, TMP36 &temp, Lcd &lcd);

    bool isDetected();

    float distance();

    void printOnLcd(String msg);

    ~HWFlight() = default;
};
