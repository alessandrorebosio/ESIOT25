#pragma once

#include "Task.h"
#include "core/Context.h"
#include "model/Hardware.h"

/**
 * CommunicationTask handles serial communication with the user. 
 * It reads input from the serial port, processes commands, and 
 * updates the system state accordingly. 
 */
class CommunicationTask final : public Task {
  private:
    Hardware &hardware;
    Context &context;

  public:
    /**
     * @brief Initialize communication task with hardware, context, baud rate, and period
     */
    explicit CommunicationTask(Hardware &hw, Context &ctx, int baud, int period);

    /**
     * @brief Periodically check for serial input and process commands
     */
    void tick(void) override;

    /**
     * @brief Default destructor
     */
    ~CommunicationTask() = default;
};
