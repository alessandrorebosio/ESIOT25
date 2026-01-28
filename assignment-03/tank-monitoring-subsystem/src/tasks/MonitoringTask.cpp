#include <Arduino.h>
#include <Sonar.h>

#include "tasks/MonitoringTask.h"

#include "config.h"

extern bool working;
extern double waterLevel;
extern long updateFrequency;

void MonitoringTask::exec(void *parameter) {
    Sonar sonar(DIST_TRIG_PIN, DIST_ECHO_PIN, MAXTIME);

    while (working) {
        waterLevel = sonar.readDistance();
        delay(updateFrequency);
    }
}
