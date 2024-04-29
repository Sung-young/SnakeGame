#include "Mission.h"

extern Snake* snake;
extern Stage* stage;

Mission::Mission() {
	length_score = 5;
	fruit_score = 0;
	poison_score = 0;
	gate_score = 0;
	total_score = 0;
}

Mission::~Mission() {
	// NULL;
}

void Mission::Update(float tic) {
	// length_score: 게임 중 최대 몸길이
	if(length_score <= snake->entire.size()) {
		SetLengthScore(snake->entire.size());
	}
	CalcTotalScore(stage->GetCurrentStage());

	// 최고점수 반영
	int best_score = GetBestScore();
	if(total_score > best_score) {
		SetBestScore(total_score);
	}

}

void Mission::Render() {
	NULL;
}

void Mission::CalcTotalScore(int stage) {
	total_score = fruit_score * 10 + poison_score * 10 + gate_score * 20 + (stage) * 50;
}

bool Mission::IsMissionClear(int stage) {
	if (length_score	>= mission_table[stage][0] && 
		fruit_score		>= mission_table[stage][1] &&
		poison_score	>= mission_table[stage][2] &&
		gate_score		>= mission_table[stage][3]) {
		
		return true;
	}
	return false;
}

int* Mission::GetCurrentMission(int stage) {
	return mission_table[stage];
}

int Mission::GetLengthScore() {
	return length_score;
}

int Mission::GetFruitScore() {
	return fruit_score;
}

int Mission::GetPoisonScore() {
	return poison_score;
}

int Mission::GetGateScore() {
	return gate_score;
}

int Mission::GetTotalScore() {
	return total_score;
}

void Mission::SetLengthScore(int score) {
	length_score = score;
}

void Mission::SetFruitScore(int score) {
	fruit_score = score;
}

void Mission::SetPoisonScore(int score) {
	poison_score = score;
}

void Mission::SetGateScore(int score) {
	gate_score = score;
}

int Mission::GetBestScore() {
	char line[10];
	ifstream data_file;

	string file_path = "score/best_score.dat";
	data_file.open(file_path);
	data_file.getline(line, 10);

	return stoi(line);
}

void Mission::SetBestScore(int best_score) {
	string line = to_string(best_score);

	ofstream data_file;
	string file_path = "score/best_score.dat";
	data_file.open(file_path);

	data_file << best_score;

	data_file.close();
}

// EOF
