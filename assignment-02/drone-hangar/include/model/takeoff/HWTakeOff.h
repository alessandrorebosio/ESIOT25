#pragma once

#include <Lcd.h>
#include <Sonar.h>
#include <TMP36.h>

class HWTakeOff final {
  private:
    Sonar &sonar;
    TMP36 &temp;

  public:
    explicit HWTakeOff(Sonar &sonar, TMP36 &temp);

    float distance(void);

    ~HWTakeOff() = default;
};
