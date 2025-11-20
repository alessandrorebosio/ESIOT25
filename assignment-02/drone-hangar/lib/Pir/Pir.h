#pragma once

#include "devices/PresenceSensor.h"

class Pir : public PresenceSensor {

  private:
    long lastTimeSync;
    int pin;
    bool detected;

  public:
    Pir(const int pin) : pin(pin) {
        this->begin();
        this->calibrate();
    };

    void begin();

    bool isDetected() override;

    void calibrate();

    void sync();

    long getLastSyncTime();

  protected:
    void updateSyncTime(long time);
};
