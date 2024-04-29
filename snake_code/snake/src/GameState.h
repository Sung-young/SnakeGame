#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include "global.h"
#include "GameMenuState.h"
#include "GameOverState.h"
#include "GameClearState.h"
#include "ItemHandler.h"
#include "GateHandler.h"
#include "Display.h"
#include "Mission.h"

class GameState: public BaseState {
public:
	int score;
	int max_width, max_height;

	GameState();
	~GameState();
	
	void Update(float tic);
	void Render();

	void InitGameStateWindow();
	void ActiveObject();
};

#endif

// EOF
