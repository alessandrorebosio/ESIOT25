#pragma once

class Context final {
  private:
    bool flightAllowed;
    bool blinking;
    bool opening;

  public:
    Context();

    void allowFlight();
    void blockFlight();

    void startBlink();
    void stopBlink();

    void openGate();
    void closeGate();

    const bool &isFlightAllowed() const;
    const bool &shouldBlink() const;
    const bool &shouldOpen() const;

    void reset();

    virtual ~Context() = default;
};
