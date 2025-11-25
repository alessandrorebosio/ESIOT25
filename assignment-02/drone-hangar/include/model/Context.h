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

    bool isOpening();

    bool isBlinking();

    void reset();
};
