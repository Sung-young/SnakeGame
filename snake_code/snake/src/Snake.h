#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "global.h"
#include "GameOverState.h"

class Snake: public BaseObject {
public:
	vector<Position> entire;
	char direction;
	int max_width, max_height;
	bool is_dead = false;
	bool is_grow = false;
	bool is_shrink = false;

	Snake();
	~Snake();

	void Update(float tic);
	void Render();

	void SpawnSnake();
	void ChangeDirection();	
	void SetDirection(int a);
	void SetDirectionWithCheck(int a, int b);
	
	Position GetHead();
	Position GetTail();
	int GetSize();
	void SetHeadPos(int y, int x);
	void SetGrow(bool flag);
	void SetDead();
	bool IsDead();
	void Shrink();
	void ApplyBlock();
};

#endif

// EOF
