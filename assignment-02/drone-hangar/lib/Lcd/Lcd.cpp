#include "Lcd.h"

#define ADDR 0x27

Lcd::Lcd(const uint8_t address, const uint8_t cols, const uint8_t rows) {
    this->lcd = new LiquidCrystal_I2C(address, cols, rows);
    this->lcd->init();
    this->lcd->backlight();
    this->clear();
}

void Lcd::print(const String text) {
    this->clear();
    this->setCursor(0, 0);
    this->lcd->print(text);
}

void Lcd::setCursor(const uint8_t x, const uint8_t y) {
    this->lcd->setCursor(x, y);
}

void Lcd::clear() { this->lcd->clear(); }
