#pragma once

namespace System {
      enum Print { DONE, NORMAL, PREALARM, ALARM };
  }

  namespace Drone {
      enum Print { DONE, INSIDE, TAKEOFF, OUTSIDE, LANDING };
  }
class Context final {
  private:
    System::Print systemPrint : 2;
    Drone::Print dronePrint : 3;

    bool flightAllowed;

    bool blinking;
    bool opening;

    bool measuring;

  public:
    Context(void);

    void reset(void);

    void printNormal(void);
    void printPreAlarm(void);
    void printAlarm(void);
    void systemPrintDone(void);

    void printInside(void);
    void printTakeOff(void);
    void printOutside(void);
    void printLanding(void);
    void dronePrintDone(void);

    void allowFlight(void);
    void blockFlight(void);

    void startBlink(void);
    void stopBlink(void);

    void openGate(void);
    void closeGate(void);

    const bool &shouldBlink(void) const;
    const bool &shouldOpen(void) const;

    bool shouldListen(void);

    bool shouldPrint(void);
    bool shouldSystemPrint(void);
    bool shouldPrintNormal(void);
    bool shouldPrintPreAlarm(void);
    bool shouldPrintAlarm(void);

    bool shouldDronePrint(void);
    bool shouldPrintInside(void);
    bool shouldPrintTakeOff(void);
    bool shouldPrintOutside(void);
    bool shouldPrintLanding(void);

    static Context &instance;

    virtual ~Context() = default;
};

typedef bool (Context::*Predicate)();
