#include "Item.h"
#include "Map.h"

extern Map *map;

Item::Item() {
	NULL;
}

Item::Item(char type, Position pos, float tic): position(pos) {
	this->type = type;
	this->drop_time = tic;
}

Item::~Item() {
	NULL;
}

void Item::Update(float tic) {
	NULL;
}

void Item::Render() {
	NULL;
}

Position Item::GetPosition() {
	return position;
}

int Item::X() {
	return position.x;
}

int Item::Y() {
	return position.y;
}

bool Item::ComparePosition(int x, int y) {
	return (position.x == x && position.y == y);
}

char Item::GetType() {
	return type;
}

float Item::GetDropType() {
	return drop_time;
}

void Item::SetPosition(Position position) {
	this->position = position;
}

void Item::SetType(char type) {
	this->type = type;
}

void Item::SetDropType(float drop_time) {
	this->drop_time = drop_time;
}

// EOF
