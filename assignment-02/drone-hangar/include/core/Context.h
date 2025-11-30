#pragma once

namespace System {
enum Print { DONE, NORMAL, PREALARM, ALARM };
}

namespace Drone {
enum Print { DONE, INSIDE, TAKEOFF, OUTSIDE, LANDING };
}

typedef const bool &Predicate;

class Context final {
  private:
    System::Print systemPrint : 2;
    Drone::Print dronePrint : 3;

    bool flightAllowed;

    bool blinking;
    bool opening;

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

    void printDone(void);

    void allowFlight(void);
    void blockFlight(void);

    void startBlink(void);
    void stopBlink(void);

    void openGate(void);
    void closeGate(void);

    Predicate shouldBlink(void);
    Predicate shouldOpen(void);
    Predicate shouldPrint(void);

    bool shouldPrintNormal(void);
    bool shouldPrintPreAlarm(void);
    bool shouldPrintAlarm(void);
    bool shouldPrintInside(void);
    bool shouldPrintTakeOff(void);
    bool shouldPrintOutside(void);
    bool shouldPrintLanding(void);

    virtual ~Context() = default;
};
