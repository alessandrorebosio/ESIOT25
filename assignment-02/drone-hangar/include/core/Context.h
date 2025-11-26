#pragma once

class Context {
  private:
    bool flightOperation;
    bool measuring;
    bool blinking;
    bool opening;

  public:
    Context();

    void allowFlightOperation();
    void blockFlightOperation();

    void startMeasuring();
    void stopMeasuring();

    void startBlink();
    void stopBlink();

    void openGate();
    void closeGate();

    bool isFlightOperationAllowed() const;
    bool isMeasured() const;
    bool shouldBlink() const;
    bool shouldOpen() const;

    void reset();

    virtual ~Context() = default;
};
