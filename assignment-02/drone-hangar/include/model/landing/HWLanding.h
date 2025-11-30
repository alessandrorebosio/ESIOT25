#pragma once

#include <Lcd.h>
#include <Sonar.h>
#include <TMP36.h>

class HWLanding final {
  private:
    Sonar &sonar;
    TMP36 &temp;

  public:
    explicit HWLanding(Sonar &sonar, TMP36 &temp);

    float distance(void);

    ~HWLanding() = default;
};
