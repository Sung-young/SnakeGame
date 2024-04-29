#include "Gate.h"

Gate::Gate() {
	NULL;
}

Gate::Gate(Position position): position(position) {
	NULL;
}

Gate::~Gate() {
	NULL;
}

void Gate::Update(float tic) {
	NULL;
}

void Gate::Render() {
	NULL;
}

Position Gate::GetPosition() {
	return position;
}

void Gate::SetPosition(Position position) {
	this->position = position;
}

void Gate::SetPosition(int x, int y) {
	this->position.x = x;
	this->position.y = y;
}

int Gate::X() {
	return this->position.x;
}

int Gate::Y() {
	return this->position.y;
}


bool Gate::ComparePosition(int x, int y) {
	return (position.x == x && position.y == y);
}


// EOF
