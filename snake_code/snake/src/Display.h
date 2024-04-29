#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "global.h"
#include "Mission.h"
#include "Stage.h"

class Display: public BaseObject {
public:
	int max_height, max_width;
	
	Display();
	~Display();

	void Update(float tic);
	void Render();

	void DisplayScore();
	void DisplayMission();

	void DisplayMessage(string msg, int height);
	void DisplayMessage(char* msg, int height, int width);
	char MissionClear(int score, int goal);
};

#endif

// EOF
