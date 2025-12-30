#pragma once

class Context final {
  private:
    bool automatic;

  public:
    /**
     * @brief Constructs a new Context object.
     */
    Context(void);

    void setAutomatic(void);
    void setManual(void);

    bool isAutomatic(void);

    void reset(void);
};
