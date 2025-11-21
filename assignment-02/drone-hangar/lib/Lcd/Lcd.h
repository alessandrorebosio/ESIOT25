#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Lcd final {
  private:
    LiquidCrystal_I2C *lcd;

  public:
    Lcd(uint8_t address, uint8_t cols, uint8_t rows);

    void print(String text);

    void setCursor(uint8_t x, uint8_t y);

    void clear();
};
