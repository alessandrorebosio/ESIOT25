#pragma once

#include <Arduino.h>

#include "model/HWPlatform.h"

class State {
  public:
    void onEnter(HWPlatform *hw);

    void onExit(HWPlatform *hw);

    void execute(HWPlatform *hw);
};
