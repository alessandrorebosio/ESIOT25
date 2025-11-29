#pragma once

#include "tasks/states/system/SystemState.h"

namespace System {

class Normal final : public SystemState {
  public:
	void onEnter(SystemTask &task, HWSystem &hw, Context &ctx);

	void onExit(SystemTask &task, HWSystem &hw, Context &ctx);

	void tick(SystemTask &task, HWSystem &hw, Context &ctx);

	~Normal() = default;
};

} // namespace System
