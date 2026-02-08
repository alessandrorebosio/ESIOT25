#include <Arduino.h>
#include <Sonar.h>

#include "tasks/MonitoringTask.h"

#include "config.h"

extern bool working;         ///< Global flag indicating if the system is working
extern double waterLevel;    ///< Global variable storing current water level distance
extern long updateFrequency; ///< Global variable storing measurement update frequency

/**
 * @brief Implementation of the monitoring task execution function.
 *
 * This function runs in a FreeRTOS task and continuously reads water level
 * from a sonar sensor. The task runs only while the system is working and
 * updates the waterLevel variable at intervals specified by updateFrequency.
 * The task runs on Core 1.
 *
 * @param parameter Task parameters (not used).
 */
void MonitoringTask::exec(void *parameter) {
    Sonar sonar(DIST_TRIG_PIN, DIST_ECHO_PIN, MAXTIME);

    while (true) {
        waterLevel = sonar.readDistance();
        delay(updateFrequency);
    }
}
