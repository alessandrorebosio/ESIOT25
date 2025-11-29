#pragma once

#include <Lcd.h>
#include <Sonar.h>
#include <TMP36.h>

class HWCheck final {
  private:
    Sonar &sonar;
    TMP36 &temp;

  public:
    explicit HWCheck(Sonar &sonar, TMP36 &temp);

    float distance(void);

    ~HWCheck() = default;
};
