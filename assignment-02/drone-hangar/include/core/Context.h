#pragma once

class Context {
  private:
    bool flightOperation;
    bool blinking;
    bool opening;

  public:
    Context();

    void allowFlightOperation();
    void blockFlightOperation();

    void startBlink();
    void stopBlink();

    void open();
    void close();

    bool isFlightOperationAllowed() const;
    bool shouldBlink() const;
    bool shouldOpen() const;

    void reset();

    virtual ~Context() = default;
};
