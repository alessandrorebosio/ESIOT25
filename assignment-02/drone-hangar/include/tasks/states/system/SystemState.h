#pragma once

class HWSystem;
class Context;

namespace System {

class SystemTask;

class SystemState {
  public:
	virtual void onEnter(SystemTask &task, HWSystem &hw, Context &ctx) = 0;

	virtual void onExit(SystemTask &task, HWSystem &hw, Context &ctx) = 0;

	virtual void tick(SystemTask &task, HWSystem &hw, Context &ctx) = 0;

	virtual ~SystemState() = default;
};

} // namespace System
