#include "Map.h"

extern Stage* stage;

Map::Map() {
	this->Load();
}

Map::~Map() {
	NULL;
}

void Map::Update(float tic) {
	NULL;
}

void Map::Render() {
	NULL;
}

void Map::Load() {
	int height = 0;
	char line[WIDTH+1];
	ifstream data_file;

	string file_path = "map/stage_" + to_string(stage->GetCurrentStage() + 1) + ".dat";
	data_file.open(file_path);

	while (!data_file.eof()) {
		data_file.getline(line, WIDTH+1);
		for (int i = 0; i < WIDTH; i++) {
			block[height][i] = line[i];
		}
		height++;
	}
}

void Map::SetBlock(int y, int x, char e) {
	block[y][x] = e;
}

void Map::SetBlock(Position position, char e) {
	int x = position.x;
	int y = position.y;
	block[y][x] = e;
}

char Map::GetBlock(int x, int y) {
	return block[y][x];
}

void Map::DeleteBlock(int y, int x) {
	SetBlock(y, x, BLOCK_SPACE);
}

// EOF
