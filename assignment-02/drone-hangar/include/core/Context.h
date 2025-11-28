#pragma once

class Context final {
  private:
    bool flightAllowed;
    bool blinking;

    bool takeOff;
    bool landing;

    bool measuring;

  public:
    Context();

    void allowFlight();
    void blockFlight();

    void startBlink();
    void stopBlink();

    void dotTakeOff();
    void doLanding();
    void startMeasuring();

    void takeOffDone();
    void landingDone();
    void stopMeasuring();

    const bool &isFlightAllowed() const;
    const bool &shouldBlink() const;
    const bool &shouldMeasure() const;
    const bool &isTakeOff() const;
    const bool &isLanding() const;

    bool isOperationDone() const;

    void reset();

    virtual ~Context() = default;
};
