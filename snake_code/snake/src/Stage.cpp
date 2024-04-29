#include "Stage.h"

Stage::Stage() {
	current_stage = 0;
}

Stage::~Stage() {
}

int Stage::GetCurrentStage() {
	return current_stage;
}

void Stage::SetNowStage(int stage) {
	this->current_stage = stage;
}

// EOF
