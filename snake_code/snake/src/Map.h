#ifndef __MAP_H__
#define __MAP_H__

#include "global.h"
#include "Snake.h"

class Map: public BaseObject {
public:
	char block[HEIGHT][WIDTH];

	Map();
	~Map();

	void Render();
	void Update(float tic);

	void Load();

	void SetBlock(int y, int x, char e);
	void SetBlock(Position position, char e);
	char GetBlock(int x, int y);
	void DeleteBlock(int y, int x);	
};

#endif

// EOF