#pragma once

namespace System {
enum Print { DONE, NORMAL, PREALARM, ALARM };
}

namespace Drone {
enum Print { DONE, INSIDE, TAKEOFF, OUTSIDE, LANDING };
}

class Context final {
  private:
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
    Context(void);

    void reset(void);

    void printNormal(void);
    void printPreAlarm(void);
    void printAlarm(void);
    void printInside(void);
    void printTakeOff(void);
    void printOutside(void);
    void printLanding(void);

    void setTakeOffMsg(void);
    void setLandingMsg(void);

    void printDone(void);

    void allowFlight(void);
    void blockFlight(void);

    void startBlink(void);
    void stopBlink(void);

    void openGate(void);
    void closeGate(void);

    void doTakeOff(void);
    void takeOffDone(void);
    void doLanding(void);
    void landingDone(void);

    const bool &isFlightAllowed(void);
    const bool &shouldBlink(void);
    const bool &shouldOpen(void);
    const bool &shouldPrint(void);
    const bool &isTakeOffInProgress(void);
    const bool &isLandingInProgress(void);

    bool shouldPrintNormal(void);
    bool shouldPrintPreAlarm(void);
    bool shouldPrintAlarm(void);
    bool shouldPrintInside(void);
    bool shouldPrintTakeOff(void);
    bool shouldPrintOutside(void);
    bool shouldPrintLanding(void);

    bool isTakeOffMsg(void);
    bool isLandingMsg(void);

    virtual ~Context() = default;
};
