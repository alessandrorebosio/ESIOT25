#include "model/HardwareFactory.h"

namespace HardwareFactory {

/**
 * @brief Create a HWBlink implementation.
 *
 * Implementation uses LED2 for blinking functionality.
 */
HWBlink *createHWBlink(Hardware &hw) {
    struct Impl : public HWBlink {
        Hardware &hw;

        Impl(Hardware &h) : hw(h) {
        }

        void turnOn(void) override {
            this->hw.getLed2().on();
        }

        void turnOff(void) override {
            this->hw.getLed2().off();
        }
    };

    return new Impl(hw);
}

/**
 * @brief Create a HWFlight implementation.
 *
 * Implementation uses PIR sensor for detection and sonar for distance measurement.
 */
HWFlight *createHWFlight(Hardware &hw) {
    struct Impl : public HWFlight {
        Hardware &hw;

        Impl(Hardware &h) : hw(h) {
        }

        bool isDetected(void) override {
            return this->hw.getPir().isDetected();
        }

        float distance(void) override {
            return measureDistance(this->hw);
        }
    };

    return new Impl(hw);
}

/**
 * @brief Create a HWGate implementation.
 *
 * Implementation uses motor for gate control with on/off and positioning.
 */
HWGate *createHWGate(Hardware &hw) {
    struct Impl : public HWGate {
        Hardware &hw;

        Impl(Hardware &h) : hw(h) {
        }

        void motorOn(void) override {
            this->hw.getMotor().on();
        }

        void motorOff(void) override {
            this->hw.getMotor().off();
        }

        void setPosition(short angle) override {
            this->hw.getMotor().setPosition(angle);
        }
    };

    return new Impl(hw);
}

/**
 * @brief Create a HWSystem implementation.
 *
 * Implementation provides system-level hardware operations including
 * button input, LED control, and temperature sensing.
 *
 * @bug There is a bug in turnOnLed2() and turnOffLed2() methods - both
 *      currently control LED3 instead of LED2. This should be corrected
 *      to match the intended behavior.
 */
HWSystem *createHWSystem(Hardware &hw) {
    struct Impl : public HWSystem {
        Hardware &hw;

        Impl(Hardware &h) : hw(h) {
        }

        bool isPressed(void) override {
            return this->hw.getButton().isPressed();
        }

        void turnOnLed1(void) override {
            this->hw.getLed1().on();
        }

        void turnOffLed1(void) override {
            this->hw.getLed1().off();
        }

        void turnOnLed2(void) override {
            this->hw.getLed3().on();
        }

        void turnOffLed2(void) override {
            this->hw.getLed3().off();
        }

        float temperature(void) override {
            return measureTemperature(this->hw);
        }
    };

    return new Impl(hw);
}

/**
 * @brief Helper function to read distance from sonar with temperature compensation.
 *
 * This function configures the sonar sensor with the current temperature
 * reading for accurate distance measurement, then reads the distance.
 *
 * @param hw Reference to the Hardware object containing the sensors.
 * @return float The measured distance with temperature compensation.
 */
float measureDistance(Hardware &hw) {
    hw.getSonar().setTemperature(hw.getTempSensor().readTemperature());
    return hw.getSonar().readDistance();
}

float measureTemperature(Hardware &hw) {
    return hw.getTempSensor().readTemperature();
}

} // namespace HardwareFactory
