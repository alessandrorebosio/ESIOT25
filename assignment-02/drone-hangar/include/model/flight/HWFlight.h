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

  public:
    explicit HWFlight(Pir &pir, Sonar &sonar, TMP36 &temp);

    bool isDetected(void);

    float distance(void);

    ~HWFlight() = default;
};
