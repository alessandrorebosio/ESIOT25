#include "TMP36.h"

#define MV_PER_C 10.0
#define ADC_RES 1024
#define SAMPLES 10
#define OFFSET 0.5
#define VREF 5.0

TMP36::TMP36(const uint8_t pin) : pin(pin) {
    pinMode(this->pin, INPUT);
}

float TMP36::readTemperature() {
    float sum = 0;
    for (uint8_t i = 0; i < SAMPLES; i++) {
        int adcValue = analogRead(this->pin);
        float voltage = (adcValue * VREF) / ADC_RES;
        sum += (voltage - OFFSET) * (1000.0 / MV_PER_C);
        delay(1);
    }

    return sum / SAMPLES;
}
