#include "tasks/SystemTask.h"

#include "tasks/states/system/Normal.h"

System::SystemTask::SystemTask(HWSystem *hw, Context &ctx, int period)
	: hardware(hw), context(ctx), state(nullptr) {
	Task::init(period);
	this->changeState(new ::System::Normal);
}

void System::SystemTask::tick() {
	this->state->tick(*this, *this->hardware, this->context);
}

void System::SystemTask::changeState(SystemState *newState) {
	if (this->state != nullptr) {
		this->state->onExit(*this, *this->hardware, this->context);
		delete this->state;
	}
	this->state = newState;
	if (this->state != nullptr) {
		this->state->onEnter(*this, *this->hardware, this->context);
	}
}

System::SystemTask::~SystemTask() {
	delete this->hardware;
	delete this->state;
}
