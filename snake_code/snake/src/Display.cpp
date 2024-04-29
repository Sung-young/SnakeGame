#include "Display.h"

extern Stage* stage;
extern Mission* mission;
extern Display* display;

Display::Display() {
	getmaxyx(stdscr, max_height, max_width);
}

Display::~Display() {
	NULL;
}

void Display::Update(float tic) {
	NULL;
}

// 점수와 미션을 렌더링
void Display::Render() {
	DisplayScore();
	DisplayMission();
}

// 점수를 화면에 표시
void Display::DisplayScore() {
	char msg[50];
	char bar[30] = "---------------------";
	int total_score = mission->total_score;
	int bound = 6;

	display->DisplayMessage(bar, bound, BOARD_WIDTH-2);

	move(bound+2, BOARD_WIDTH);
	printw("[  SCORE BOARD  ]");

	// 최고 점수 출력
	int best_score = mission->GetBestScore();
	snprintf(msg, sizeof(msg), "BEST  : %03d", best_score);
	display->DisplayMessage(msg, bound+4, BOARD_WIDTH+3);

	mission->CalcTotalScore(stage->GetCurrentStage());
	snprintf(msg, sizeof(msg), "SCORE : %03d", total_score);
	display->DisplayMessage(msg, bound+5, BOARD_WIDTH+3);

	display->DisplayMessage(bar, bound+8, BOARD_WIDTH-2);
}

// 미션을 화면에 표시
void Display::DisplayMission() {
	int bound = 14;
	char msg[50];
	char bar[30] = "---------------------";
	int *current_mission = mission->GetCurrentMission(stage->GetCurrentStage());
	
	move(bound+2, BOARD_WIDTH);
	printw("[ MISSION BOARD ]");

	snprintf(msg, sizeof(msg), "Length : %d/%d [%c]", mission->GetLengthScore(), current_mission[0], MissionClear(mission->GetLengthScore(), current_mission[0]));
	display->DisplayMessage(msg, bound+5, BOARD_WIDTH);

	snprintf(msg, sizeof(msg), "Fruit  : %d/%d [%c]", mission->GetFruitScore(), current_mission[1], MissionClear(mission->GetFruitScore(), current_mission[1]));
	display->DisplayMessage(msg, bound+7, BOARD_WIDTH);

	snprintf(msg, sizeof(msg), "Poison : %d/%d [%c]", mission->GetPoisonScore(), current_mission[2], MissionClear(mission->GetPoisonScore(), current_mission[2]));
	display->DisplayMessage(msg, bound+9, BOARD_WIDTH);

	snprintf(msg, sizeof(msg), "Gate   : %d/%d [%c]", mission->GetGateScore(), current_mission[3], MissionClear(mission->GetGateScore(), current_mission[3]));
	display->DisplayMessage(msg, bound+11, BOARD_WIDTH);

	display->DisplayMessage(bar, bound+13, BOARD_WIDTH-2);
}

// 특정 메시지를 화면에 출력
void Display::DisplayMessage(string msg, int height) {
	move(height, (WIDTH - msg.length())/2);
	printw(msg.c_str());
}

// 특정 메시지를 화면에 출력
void Display::DisplayMessage(char* msg, int height, int width) {
	move(height, width);
	printw(msg);
}

// 각 미션별 클리어 여부를 반환
char Display::MissionClear(int score, int goal) {
	if (score >= goal)
		return 'X';
	else
		return ' ';
}



// EOF
