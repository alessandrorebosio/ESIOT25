#include "model/state/Inside.h"

void Inside::onEntry(HWPlatform &hw) {
    hw.printOnLcd(this->toString());
    hw.ledOffs();
}

void Inside::onExit(HWPlatform &hw) {
}

String Inside::toString() {
    return "Drone Inside";
}
