#pragma once

/**
 * @file Context.h
 * @brief Defines the Context class for managing system and drone state transitions.
 */

namespace System {
/**
 * @brief System print status enumeration.
 */
enum Print { DONE, NORMAL, PREALARM, ALARM };
} // namespace System

namespace Drone {
/**
 * @brief Drone print status enumeration.
 */
enum Print { DONE, INSIDE, TAKEOFF, OUTSIDE, LANDING };
} // namespace Drone

/**
 * @class Context
 * @brief Central state management class for drone control system.
 *
 * This class manages the system state including print messages,
 * flight permissions, gate control, and operation status.
 */
class Context final {
  private:
    /**
     * @brief Internal message types for drone operations.
     */
    enum Messages { NONE, TAKEOFF, LANDING };

    System::Print systemPrint : 2;
    Drone::Print dronePrint : 3;
    Messages msg : 2;

    bool flightAllowed;
    bool print;
    bool blinking;
    bool opening;
    bool takeoff;
    bool landing;

  public:
    /**
     * @brief Constructs a new Context object.
     */
    Context(void);

    /**
     * @brief Resets all context states to default values.
     */
    void reset(void);

    // ============ Print Status Setters ============

    /**
     * @brief Set system print status to NORMAL and request printing.
     */
    void printNormal(void);

    /**
     * @brief Set system print status to PREALARM and request printing.
     */
    void printPreAlarm(void);

    /**
     * @brief Set system print status to ALARM and request printing.
     */
    void printAlarm(void);

    /**
     * @brief Set drone print status to INSIDE and request printing.
     */
    void printInside(void);

    /**
     * @brief Set drone print status to TAKEOFF and request printing.
     */
    void printTakeOff(void);

    /**
     * @brief Set drone print status to OUTSIDE and request printing.
     */
    void printOutside(void);

    /**
     * @brief Set drone print status to LANDING and request printing.
     */
    void printLanding(void);

    /**
     * @brief Set both print statuses to DONE and disable printing.
     */
    void printDone(void);

    // ============ Message Management ============

    /**
     * @brief Set pending message to TAKEOFF.
     */
    void setTakeOffMsg(void);

    /**
     * @brief Set pending message to LANDING.
     */
    void setLandingMsg(void);

    /**
     * @brief Clear any pending message.
     */
    void clearMsg(void);

    // ============ Flight Control ============

    /**
     * @brief Allow flight operations.
     */
    void allowFlight(void);

    /**
     * @brief Block flight operations.
     */
    void blockFlight(void);

    // ============ Blink Control ============

    /**
     * @brief Enable blinking.
     */
    void startBlink(void);

    /**
     * @brief Disable blinking.
     */
    void stopBlink(void);

    // ============ Gate Control ============

    /**
     * @brief Open the gate.
     */
    void openGate(void);

    /**
     * @brief Close the gate.
     */
    void closeGate(void);

    // ============ Takeoff Operations ============

    /**
     * @brief Start takeoff operation.
     */
    void doTakeOff(void);

    /**
     * @brief Mark takeoff as completed and reset both operation flags.
     */
    void takeOffDone(void);

    // ============ Landing Operations ============

    /**
     * @brief Start landing operation.
     */
    void doLanding(void);

    /**
     * @brief Mark landing as completed and reset both operation flags.
     */
    void landingDone(void);

    // ============ State Getters ============

    /**
     * @brief Get flight permission status.
     * @return Constant reference to flightAllowed flag.
     */
    const bool &isFlightAllowed(void);

    /**
     * @brief Get blinking status.
     * @return Constant reference to blinking flag.
     */
    const bool &shouldBlink(void);

    /**
     * @brief Get gate opening status.
     * @return Constant reference to opening flag.
     */
    const bool &shouldOpen(void);

    /**
     * @brief Get print request status.
     * @return Constant reference to print flag.
     */
    const bool &shouldPrint(void);

    /**
     * @brief Check if takeoff is in progress.
     * @return Constant reference to takeoff flag.
     */
    const bool &isTakeOffInProgress(void);

    /**
     * @brief Check if landing is in progress.
     * @return Constant reference to landing flag.
     */
    const bool &isLandingInProgress(void);

    // ============ Print Status Checkers ============

    /**
     * @brief Check if NORMAL status should be printed.
     * @return true if systemPrint is NORMAL.
     */
    bool shouldPrintNormal(void);

    /**
     * @brief Check if PREALARM status should be printed.
     * @return true if systemPrint is PREALARM.
     */
    bool shouldPrintPreAlarm(void);

    /**
     * @brief Check if ALARM status should be printed.
     * @return true if systemPrint is ALARM.
     */
    bool shouldPrintAlarm(void);

    /**
     * @brief Check if INSIDE status should be printed.
     * @return true if dronePrint is INSIDE.
     */
    bool shouldPrintInside(void);

    /**
     * @brief Check if TAKEOFF status should be printed.
     * @return true if dronePrint is TAKEOFF.
     */
    bool shouldPrintTakeOff(void);

    /**
     * @brief Check if OUTSIDE status should be printed.
     * @return true if dronePrint is OUTSIDE.
     */
    bool shouldPrintOutside(void);

    /**
     * @brief Check if LANDING status should be printed.
     * @return true if dronePrint is LANDING.
     */
    bool shouldPrintLanding(void);

    // ============ Message Checkers ============

    /**
     * @brief Check and consume TAKEOFF message.
     * @return true if TAKEOFF message was pending (consumes it).
     */
    bool isTakeOffMsg(void);

    /**
     * @brief Check and consume LANDING message.
     * @return true if LANDING message was pending (consumes it).
     */
    bool isLandingMsg(void);

    /**
     * @brief Virtual destructor for polymorphic base class.
     */
    virtual ~Context() = default;
};