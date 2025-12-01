#pragma once

/**
 * @brief Abstract base class for flight detection hardware.
 * 
 * This interface combines motion detection and distance measurement
 * capabilities, typically used for detecting objects or obstacles
 * in a flight path or similar application.
 */
class HWFlight {
  public:
    /**
     * @brief Construct a new HWFlight object.
     */
    HWFlight() = default;

    /**
     * @brief Check if motion or an object is detected.
     * 
     * @return true If motion or an object is detected.
     * @return false If no motion or object is detected.
     */
    virtual bool isDetected(void) = 0;

    /**
     * @brief Get the distance to a detected object.
     * 
     * @return float The measured distance to the object.
     */
    virtual float distance(void) = 0;

    /**
     * @brief Destroy the HWFlight object.
     */
    virtual ~HWFlight() = default;
};
