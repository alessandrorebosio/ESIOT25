#pragma once

namespace System {
enum Print { NONE, AUTOMATIC, MANUAL };
}

class Context final {
  private:
    bool automatic;
    bool print = true;

    System::Print systemPrint : 2;

    void setToPrint(System::Print value);

  public:
    /**
     * @brief Constructs a new Context object.
     */
    Context(void);

    void printAutomatic(void);
    void printManual(void);

    void clearPrint(void);

    /**
     * @brief Get print request status.
     * @return Constant reference to print flag.
     */
    const bool &shouldPrint(void);

    void setAutomatic(void);
    void setManual(void);

    bool isAutomatic(void);

    void reset(void);
};
