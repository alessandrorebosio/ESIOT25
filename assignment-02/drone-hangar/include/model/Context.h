#pragma once

class Context {
  private:
    bool opening;

  public:
    Context();

    void startOpening();

    void stopOpening();

    bool isOpening();

    void reset();
};
