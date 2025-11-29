#pragma once

#include "tasks/states/system/SystemState.h"

namespace System {

class Alarm final : public SystemState {
  public:
	void onEnter(SystemTask &task, HWSystem &hw, Context &ctx);

	void onExit(SystemTask &task, HWSystem &hw, Context &ctx);

	void tick(SystemTask &task, HWSystem &hw, Context &ctx);

	~Alarm() = default;
};

} // namespace System
