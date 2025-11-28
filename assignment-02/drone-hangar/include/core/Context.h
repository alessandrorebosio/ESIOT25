#pragma once

class Context final {
  private:
    bool flightAllowed;
    bool blinking;

    bool takeOff;
    bool landing;

  public:
    Context();

    void allowFlight();
    void blockFlight();

    void startBlink();
    void stopBlink();

    void dotTakeOff();
    void doLanding();

    const bool &isFlightAllowed() const;
    const bool &shouldBlink() const;

    bool isOperationDone() const;
    bool isTakeOff() const;
    bool isLanding() const;

    void reset();

    virtual ~Context() = default;
};
