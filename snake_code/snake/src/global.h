// #pragma once
#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <chrono>
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <unistd.h>
#include <vector>

#include "BaseObject.h"
#include "BaseState.h"

#include "Stage.h"

using namespace std;

// global variable header

// position of object (items/gate)
class Position {
public:
	int x, y;
	Position(int x, int y): x(x), y(y) {}
	Position(): x(0), y(0) {}
	
	int& X() {
		return x;
	}
	int& Y() {
		return x;
	}
};

// screan info
#define WIDTH 62
#define HEIGHT 32

#define STATE_DELAY_TIME 100000

#define BOARD_WIDTH WIDTH+5

// map data
#define BLOCK_SPACE			'0'
#define BLOCK_WALL          '1'
#define BLOCK_IMMUNE_WALL	'2'
#define BLOCK_HEAD			'3'
#define BLOCK_BODY			'4'
#define BLOCK_FRUIT			'5'
#define BLOCK_POISON		'6'
#define BLOCK_GATE			'7'
#define BLOCK_INVISIBLE		'9'

// snake <-> block
#define HEAD	BLOCK_HEAD
#define BODY	BLOCK_BODY

// snake position
#define START_POS_X 30
#define START_POS_Y 26

// snake directions
#define DIR_DOWN	0
#define DIR_UP		1
#define DIR_LEFT	2
#define DIR_RIGHT	3

// hp data
#define SNAKE_INIT_LEN		5
#define SNAKE_DEAD_LEN		3

// item
#define DROP_ITEM_INTERVAL	3.0f
#define DROP_GATE_INTERVAL	7.0f
#define DROP_ITEM_EXPIRE	9.0f

#define ITEM_FRUIT		BLOCK_FRUIT
#define ITEM_POISON		BLOCK_POISON
#define MAX_ITEMS	3

// keyboard
#define INPUT_YES	'y'
#define INPUT_NO	'n'
#define INPUT_QUIT	'q'

#define MAX_STAGE_LEVEL 3

#endif

// EOF
