#pragma once

#include <Lcd.h>
#include <Sonar.h>
#include <TMP36.h>

class HWCheck final {
  private:
    Sonar &sonar;
    TMP36 &temp;
    Lcd &lcd;

  public:
    explicit HWCheck(Sonar &sonar, TMP36 &temp, Lcd &lcd);

    float distance();

    void printOnLcd(String msg);

    ~HWCheck() = default;
};
