#ifndef __GAME_MENU_STATE__H__
#define __GAME_MENU_STATE__H__

#include "global.h"
#include "Stage.h"
#include "GameState.h"
#include "StateHandler.h"

class GameMenuState: public BaseState {
public:
	int max_width, max_height;

	GameMenuState();
	~GameMenuState();

	void Update(float tic);
	void Render();

	void Load();

	int SelectMenu();
	int GetUserInput();
};

#endif

// EOF
