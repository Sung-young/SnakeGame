#ifndef __STAGE_H__
#define __STAGE_H__

class Stage {
public:
	int current_stage;

	Stage();
	~Stage();

	int GetCurrentStage();
	void SetNowStage(int stage);
};

#endif

// EOF
