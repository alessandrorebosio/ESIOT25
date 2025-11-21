#include "model/state/Outside.h"

void Outside::onEntry(HWPlatform &hw) {
    hw.printOnLcd(this->toString());
    hw.ledOffs();
}

void Outside::onExit(HWPlatform &hw) {
}

String Outside::toString() {
    return "Drone Outside";
}
