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
    Context();

    void reset();

    void printNormal();
    void printPreAlarm();
    void printAlarm();
    void printDone();

    void allowFlight();
    void blockFlight();

    void startBlink();
    void stopBlink();

    void openGate();
    void closeGate();

    const bool &shouldBlink() const;
    const bool &shouldOpen() const;

    bool shouldPrint();
    bool shouldPrintNormal();
    bool shouldPrintPreAlarm();
    bool shouldPrintAlarm();

    static Context *instance;

    virtual ~Context() = default;
};

typedef bool (Context::*Predicate)();
