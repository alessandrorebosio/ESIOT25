#pragma once

class Context final {
  private:
    bool flightAllowed;
    bool blinking;
    bool opening;

    bool takeOff;
    bool landing;

    bool measuring;

  public:
    Context();

    void allowFlight();
    void blockFlight();

    void startBlink();
    void stopBlink();

    void openGate();
    void closeGate();

    void doTakeOff();
    void doLanding();
    void startMeasuring();

    void takeOffDone();
    void landingDone();
    void stopMeasuring();

    const bool &isFlightAllowed() const;
    const bool &shouldBlink() const;
    bool shouldMeasure();
    const bool &isTakeOff() const;
    const bool &isLanding() const;
    const bool &shouldOpen() const;

    bool isOperationDone();

    void reset();

    static Context* instance;

    virtual ~Context() = default;
};
