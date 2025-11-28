#pragma once

#include <Sonar.h>
#include <TMP36.h>

class HWCheck final {
  private:
    Sonar &sonar;
    TMP36 &temp;

  public:
    HWCheck(Sonar &sonar, TMP36 &temp);  

    float distance();

    ~HWCheck() = default;
};
