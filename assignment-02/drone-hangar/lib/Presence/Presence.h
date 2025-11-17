#ifndef PRESENCE_H
#define PRESENCE_H

#include "IPresence.h"

/**
 * @file Presence.h
 * @brief Concrete presence sensor implementation using a digital pin.
 *
 * The `Presence` class reads a configured digital input pin to determine
 * whether presence is currently detected. It implements the `IPresence`
 * interface so it can be swapped with other presence sensor implementations.
 */
class Presence : public IPresence {
  private:
    uint8_t pin;

  public:
    /**
     * @brief Construct a new Presence sensor instance.
     * @param pin Arduino digital pin number connected to the sensor output.
     */
    Presence(uint8_t pin);

    /**
     * @brief Initialize the presence sensor instance.
     *
     * Configures the digital input pin and performs any required startup
     * calibration so the sensor is ready to provide reliable `isHere()`
     * readings. Call this during the system setup phase.
     */
    void begin();

    /**
     * @brief Check whether presence is detected by reading the pin.
     * @return true if the sensor reports presence, false otherwise.
     */
    bool isHere();
};

#endif