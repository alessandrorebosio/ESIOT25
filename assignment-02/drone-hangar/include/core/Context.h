#pragma once

class Context final {
  private:
    enum SystemPrint { DONE, NORMAL, PREALARM, ALARM };

    SystemPrint systemPrint : 2;

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
    void printDone(void);

    void allowFlight(void);
    void blockFlight(void);

    void startBlink(void);
    void stopBlink(void);

    void openGate(void);
    void closeGate(void);

    void startMeasuring(void);
    void stopMeasuring(void);

    const bool &shouldBlink(void) const;
    const bool &shouldOpen(void) const;
    const bool &shouldMeasure(void) const;

    bool shouldListen(void);

    bool shouldPrint(void);
    bool shouldPrintNormal(void);
    bool shouldPrintPreAlarm(void);
    bool shouldPrintAlarm(void);

    static Context &instance;

    virtual ~Context() = default;
};

typedef bool (Context::*Predicate)();
