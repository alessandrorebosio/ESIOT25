#pragma once

#include "common/State.h"
#include "model/HWPlatform.h"

class Outside : public State<HWPlatform> {
  public:
    void onEntry(HWPlatform &hw) override;

    void onExit(HWPlatform &hw) override;

    String toString();
};
