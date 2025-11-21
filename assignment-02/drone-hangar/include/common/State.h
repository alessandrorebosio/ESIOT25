#pragma once

#include <Arduino.h>

template <typename T> class State {
  public:
    virtual void onEntry(T &t) = 0;

    virtual void onExit(T &t) = 0;
};
