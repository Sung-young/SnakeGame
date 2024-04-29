#ifndef __GAME_OVER_STATE__H__
#define __GAME_OVER_STATE__H__

#include "GameState.h"
#include "Display.h"

class GameOverState: public BaseState {
public:
	int max_width, max_height;

	GameOverState();
	~GameOverState();

	void Update(float tic);
	void Render();
	
	void Load();

	char AskRetry();
	char UserInput();

	// new
	void ShowCauseOfDeath();
};

#endif

// EOF
