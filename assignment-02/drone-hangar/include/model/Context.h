#pragma once

class Context {
  private:
    bool opening;
    bool blinking;

  public:
    Context();

    void startOpening();

    void startBlinking();

    void stopOpening();

    void stopBlinking();

    bool shouldOpen();

    bool shouldBlink();

    void reset();

    virtual ~Context() = default;
};
