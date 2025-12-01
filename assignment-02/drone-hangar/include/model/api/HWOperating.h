#pragma once

/**
 * @brief Abstract base class for operating hardware that measures distance.
 *
 * This interface provides a pure virtual method for obtaining distance measurements
 * from a hardware sensor. Concrete implementations should provide the specific
 * hardware interaction logic.
 */
class HWOperating {
  public:
    /**
     * @brief Construct a new HWOperating object.
     */
    HWOperating() = default;

    /**
     * @brief Get the current distance measurement.
     *
     * @return float The measured distance in the sensor's native units.
     */
    virtual float distance(void) = 0;

    /**
     * @brief Destroy the HWOperating object.
     */
    virtual ~HWOperating() = default;
};
