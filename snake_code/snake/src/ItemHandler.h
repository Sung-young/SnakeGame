#ifndef __ITEM_HANDLER_H__
#define __ITEM_HANDLER_H__

#include "global.h"
#include "Snake.h"
#include "Item.h"

class ItemHandler: public BaseObject {
public:
	vector<Item> item_list;
	int max_height, max_width;
	float last_drop_time = 0;

	ItemHandler();
	~ItemHandler();

	void Update(float tic);
	void Render();

	Position GetRandomPosition();	
	void AddItem(char item_type, float tic);
	void DeleteExpiredItems(float tic);
	void DeleteBlock(int y, int x);
	void ApplyBlock();	
};

#endif

// EOF
