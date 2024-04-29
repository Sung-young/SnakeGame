#ifndef __ITEM_H__
#define __ITEM_H__

#include "global.h"

class Item: public BaseObject {
public:    
	Position position;
	char type = '\x00';
	float drop_time = 0;

	Item();
	Item(char type, Position position, float tic);
	~Item();

	void Update(float tic);
	void Render();

	Position GetPosition();
	int X();
	int Y();
	bool ComparePosition(int x, int y);
	char GetType();
	float GetDropType();

	void SetPosition(Position position);
	void SetType(char type);
	void SetDropType(float drop_time);
	
};

#endif

// EOF
