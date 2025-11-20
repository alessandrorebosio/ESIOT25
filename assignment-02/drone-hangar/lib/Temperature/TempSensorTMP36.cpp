#include "TempSensorTMP36.h"

void TempSensorTMP36::begin() { pinMode(this->pin, INPUT); }

float TempSensorTMP36::getTemperature() {
    float values[5];
    float max = -1;
    float min = 100;

    for (int i = 0; i < 5; i++) {
        int value = analogRead(pin);
        /* this is the formula for the TMP36*/
        float valueInCelsius = ((value * 0.00488) - 0.5) / 0.01;
        values[i] = valueInCelsius;
        if (valueInCelsius < min) {
            min = valueInCelsius;
        } else if (valueInCelsius > max) {
            max = valueInCelsius;
        }
    }
    float sum = 0;
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if ((values[i] > min) && (values[i] < max)) {
            sum = sum + values[i];
            count++;
        }
    }
    if (count == 0) {
        return values[0];
    } else {
        return sum / count;
    }
}
