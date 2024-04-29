#ifndef __GAME_CLEAR_STATE__H__
#define __GAME_CLEAR_STATE__H__

#include "GameState.h"
#include "Display.h"

class GameClearState: public BaseState {
public:
	int max_width, max_height;

	GameClearState();
	~GameClearState();

	void Update(float tic);
	void Render();
	
	void Load();

	// new
	char UserInput();
};

#endif

// EOF
