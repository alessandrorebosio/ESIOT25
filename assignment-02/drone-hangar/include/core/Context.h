#pragma once

class Context final {
  private:
    bool flightAllowed;
    bool blinking;

  public:
    Context();

    void allowFlight();
    void blockFlight();

    void startBlink();
    void stopBlink();

    const bool &isFlightAllowed() const;
    const bool &shouldBlink() const;

    void reset();

    virtual ~Context() = default;
};
