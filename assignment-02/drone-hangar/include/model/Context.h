#pragma once

class Context {
  private:
    bool flightOperation;
    bool blinking;
    bool opening;
    bool inside;

  public:
    Context();

    void allowFlightOperation();
    void blockFlightOperation();

    void startBlink();
    void stopBlink();

    void open();
    void close();

    void droneInside();
    void droneOutside();

    bool isFlightOperationAllowed() const;
    bool isInside();
    bool shouldBlink() const;
    bool shouldOpen() const;

    void reset();

    virtual ~Context() = default;
};
