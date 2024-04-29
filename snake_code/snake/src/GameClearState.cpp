#include "GameClearState.h"

extern Display* display;

GameClearState::GameClearState() {
	NULL;
}

GameClearState::~GameClearState() {
	NULL;
}

#include <iostream>

// GameClearState 전체 업데이트
void GameClearState::Update(float tic) {
	string msg1 = "[ Congraturation!! ]";
	string msg2 = "[ Press Q to quit game ]";

	refresh();
	Load();


	display->DisplayMessage(msg1, 18);	
	display->DisplayMessage(msg2, 20);

	while(true) {
		char answer = getch();
		if (answer == INPUT_QUIT) {
			ExitProcess();
		}	
	}	
}

void GameClearState::Render() {
	// 점수 표시
	display->Render();
}

// GameClearState 데이터를 파일에서 읽어옴
void GameClearState::Load() {
	int height = 0;
	char line[WIDTH+1];
	ifstream data_file;
	
	string file_path = "State/GameClearState.dat";
	data_file.open(file_path);
	
	while (!data_file.eof()) {
		data_file.getline(line, WIDTH+1);
		for (int width = 0; width < WIDTH; width++) {
			move(height, width);
			if (line[width] == ' ') {
				addch(char(' '));
			} else if (line[width] == '1') {
				addch(char(219));
			} else if (line[width] == '2') {
				addch(char(219));
			}
		}
		height++;
	}
}

char GameClearState::UserInput() {
	char input = getch();
	endwin();
	clear();

	return input;
}

// EOF
