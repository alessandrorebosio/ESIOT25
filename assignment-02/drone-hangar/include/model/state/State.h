#pragma once

#include <Arduino.h>

class State {
  public:
    void onEnter();

    void onExit();

    void thick();

    virtual ~State() = default;
};
