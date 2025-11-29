#pragma once

#include "tasks/states/system/SystemState.h"

namespace System {

class PreAlarm final : public SystemState {
  public:
	void onEnter(SystemTask &task, HWSystem &hw, Context &ctx);

	void onExit(SystemTask &task, HWSystem &hw, Context &ctx);

	void tick(SystemTask &task, HWSystem &hw, Context &ctx);

	~PreAlarm() = default;
};

} // namespace System
