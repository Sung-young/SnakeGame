#include "StateHandler.h"

int current_width;
int current_height;
string cause_of_death = "INIT";
chrono::steady_clock::time_point start_time;
BaseState *current_state;
Display* display;

// 게임 전체 실행을 담당하는 드라이버
void ExecuteDriver() {
	InitState();
	while(true) {
		Update(GetTic());
		Render();
		DelayState();
	}
	ExitProcess();
}

// State 초기화
void InitState() {
	// 글로벌 타이버 초기화
	InitGlobalTimer();
	// GameMenuState로 전환
	current_state = new GameMenuState();
}

// 게임 전역 tic만큼 지연
void DelayState() {
	usleep(STATE_DELAY_TIME);
}

// 전체 프로세스 종료
void ExitProcess() {
	delete current_state;
	exit(1);
}

// 각 State에 해당하는 Update()를 호출
void Update(float tic) {
	current_state->Update(tic);
}

// 각 State에 해당하는 Render()를 호출
void Render() {
	current_state->Render();
}

// 게임 전역 타이머 초기화
void InitGlobalTimer() {
	start_time = chrono::steady_clock::now();
}

// tic 계산
float GetTic() {
	auto endTime = chrono::steady_clock::now();
	chrono::duration<float> elapsed_seconds = endTime - start_time;
	float tic_toc = (float)elapsed_seconds.count();

	return tic_toc;
}

// 현재 State를 변경
void ChangeState(BaseState* state) {
	delete current_state;
	current_state = state;
}

// EOF
