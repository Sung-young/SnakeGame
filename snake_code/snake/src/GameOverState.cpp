#include "GameOverState.h"

extern Display* display;
extern string cause_of_death;

GameOverState::GameOverState() {
	NULL;
}

GameOverState::~GameOverState() {
	NULL;
}

// GameOverState 전체 업데이트
void GameOverState::Update(float tic) {
	refresh();
	Load();

	// 게임 오버인 이유 출력
	ShowCauseOfDeath();
	
	char answer = AskRetry();
	if (answer == INPUT_YES) {
		ChangeState(new GameState());
	} else if (answer == INPUT_NO) {
		ExitProcess();
	}
}

void GameOverState::Render() {
	display->Render();
}

// GameOverState 데이터를 파일에서 읽어옴
void GameOverState::Load() {
	int height = 0;
	char line[WIDTH+1];
	ifstream data_file;
	
	string file_path = "State/GameOverState.dat";
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

// 다시 시도할지 물음
char GameOverState::AskRetry() {
	string msg = "[ Game Over....! Retry? (y/n) ]";
	display->DisplayMessage(msg, 26);

	return UserInput();
}

// 사용자로부터 입력을 받음
char GameOverState::UserInput() {
	char input = getch();
	endwin();
	clear();

	return input;
}


void GameOverState::ShowCauseOfDeath() {
	string msg = "[ Cause of Game Over ]  ";
	display->DisplayMessage(msg, 19);
	display->DisplayMessage(cause_of_death, 21);
}


// EOF
