#include "model/state/Takeoff.h"

void Takeoff::onEntry(HWPlatform &hw) {
    hw.printOnLcd(this->toString());
}

void Takeoff::onExit(HWPlatform &hw) {
}

String Takeoff::toString() {
    return "Takeoff";
}
