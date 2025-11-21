#include "model/state/Landing.h"

void Landing::onEntry(HWPlatform &hw) {
    hw.printOnLcd(this->toString());
}

void Landing::onExit(HWPlatform &hw) {
}

String Landing::toString() {
    return "Drone Landing";
}
