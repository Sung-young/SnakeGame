#include "Snake.h"

extern Map *map;
extern string cause_of_death;

Snake::Snake() {
	SetDirection(DIR_LEFT);
	getmaxyx(stdscr, max_height, max_width);
	SpawnSnake();
}

Snake::~Snake() {
	NULL;
}

void Snake::Update(float tic) {
	Position head;
	// 최소 체력이하면 죽음
	if (entire.size() <= SNAKE_DEAD_LEN) {
		cause_of_death = "< Body length is less than the minimum length... >";
		SetDead();
		return;
	}
	// 진행 방향 전환
	ChangeDirection();

	if(is_dead) {
		return ;
	}
	if (is_grow) {
		SetGrow(false);
	} else {
		Shrink();
	}
}

void Snake::Render() {
	NULL;
}

void Snake::SpawnSnake() {
	for (int i = 0; i < SNAKE_INIT_LEN; i++) {
		entire.push_back(Position(START_POS_X + i, START_POS_Y));
	}
}

void Snake::ChangeDirection() {
	int input;
	Position head;
	
	// 입력한 키가 반대 방향만 아니면 방향을 업데이트 해줌.
	// 만약 반대 방향이면 죽음.
	input = getch();
	switch (input) {
	case KEY_LEFT:
		SetDirectionWithCheck(DIR_LEFT, DIR_RIGHT);
		break;
	case KEY_RIGHT:
		SetDirectionWithCheck(DIR_RIGHT, DIR_LEFT);	
		break;
	case KEY_UP:
		SetDirectionWithCheck(DIR_UP, DIR_DOWN);
		break;
	case KEY_DOWN:
		SetDirectionWithCheck(DIR_DOWN, DIR_UP);
		break;
	}

	head = GetHead();
	switch (direction) {
	case DIR_LEFT:
		entire.insert(entire.begin(), Position(head.x - 1, head.y));
		break;
	case DIR_RIGHT:
		entire.insert(entire.begin(), Position(head.x + 1, head.y));
		break;
	case DIR_UP:
		entire.insert(entire.begin(), Position(head.x, head.y - 1));
		break;
	case DIR_DOWN:
		entire.insert(entire.begin(), Position(head.x, head.y + 1));
		break;
	}
}

void Snake::SetDirection(int dir) {
	direction = dir;
}

void Snake::SetDirectionWithCheck(int dir, int inv) {
	if (direction == inv) {
		cause_of_death = "< Snake can't turn back... >";
		SetDead();
		return;
	}
	SetDirection(dir);
}

Position Snake::GetHead() {
	return entire[0];
}

Position Snake::GetTail() {
	return entire[GetSize() - 1];
}

int Snake::GetSize() {
	return entire.size();
}

void Snake::SetHeadPos(int y, int x) {
	entire[0].x = x;
	entire[0].y = y;
}

void Snake::SetGrow(bool flag) {
	is_grow = flag;
}

void Snake::SetDead() {
	is_dead = true;
}

bool Snake::IsDead() {
	return is_dead;
}

void Snake::Shrink() {
	map->SetBlock(GetTail(), BLOCK_SPACE);
	entire.pop_back();
}

void Snake::ApplyBlock() {
	// head
	map->SetBlock(GetHead(), HEAD);
	// body
	for (int i = 1; i < entire.size(); i++) {
		map->SetBlock(entire[i], BODY);
	}
}

// EOF
