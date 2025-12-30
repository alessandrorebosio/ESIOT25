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

    void printDone(void);

    /**
     * @brief Get print request status.
     * @return Constant reference to print flag.
     */
    const bool &shouldPrint(void);

    void setAutomatic(void);
    void setManual(void);

    bool isAutomatic(void);

    /**
     * @brief Check if AUTOMATIC status should be printed.
     * @return true if systemPrint is AUTOMATIC.
     */
    bool shouldPrintAutomatic(void);

    /**
     * @brief Check if MANUAL status should be printed.
     * @return true if systemPrint is MANUAL.
     */
    bool shouldPrintManual(void);

    void reset(void);
};
