#ifndef __MISSION_H__
#define __MISSION_H__

#include "global.h"
#include "Snake.h"
#include "Stage.h"

class Mission: public BaseObject {
public:
	// mission: 최대 길이, 과일, 독, 게이트
	int mission_table[4][4] = {
		{6, 2, 1, 0},
		{7, 2, 1, 1},
		{8, 3, 3, 3},
		{10, 5, 4, 2},
	};
	int length_score, fruit_score, poison_score, gate_score, total_score;

	Mission();
	~Mission();

	void Update(float tic);
	void Render();

	void CalcTotalScore(int stage);
	bool IsMissionClear(int stage);

	int *GetCurrentMission(int stage);
	
	int GetLengthScore();
	int GetFruitScore();
	int GetPoisonScore();
	int GetGateScore();
	int GetTotalScore();
	
	void SetLengthScore(int score);
	void SetFruitScore(int score);
	void SetPoisonScore(int score);
	void SetGateScore(int score);

	// new
	int GetBestScore();
	void SetBestScore(int best_score);
};

#endif

// EOF
