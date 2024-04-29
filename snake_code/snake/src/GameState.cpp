#include "GameState.h"

extern Stage* stage;

Map* map;
Snake* snake;
ItemHandler* item_hdlr;
GateHandler* gate_hdlr;
Mission* mission;
extern Display* display;
extern string cause_of_death;

GameState::GameState() {
	srand(time(NULL));

	// 필요한 객체들과 핸들러들 생성
	map = new Map();

	snake = new Snake();
	item_hdlr = new ItemHandler();
	gate_hdlr = new GateHandler();

	mission = new Mission();
	display = new Display();

	InitGameStateWindow();
	refresh();
}

GameState::~GameState() {
	delete map;
	nodelay(stdscr, false);
	endwin();
}

// GameState 전체 업데이트
void GameState::Update(float tic) {
	// 스테이지를 클리어한 경우
	int stage_level = stage->GetCurrentStage();
	if (mission->IsMissionClear(stage_level)) {
		InitState();

		if(stage_level == MAX_STAGE_LEVEL) {
			ChangeState(new GameClearState());
			return ;
		}
		
		// InitState();
		stage->SetNowStage(stage_level+1);
		ChangeState(new GameState());

		return;
	}

	// Update() 함수들 일괄 호출
	snake->Update(tic);
	ActiveObject();
	
	item_hdlr->Update(tic);
	gate_hdlr->Update(tic);
	
	mission->Update(tic);
	display->Update(tic);
}

void GameState::Render() {
	display->Render();

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			switch (map->GetBlock(j, i)) {
			case BLOCK_SPACE:
				mvaddch(i, j, ' ');
				break;
			case BLOCK_WALL:
				mvaddch(i, j, '#');
				break;
			case BLOCK_IMMUNE_WALL:
				mvaddch(i, j, '#');
				break;
			case BLOCK_HEAD:
				mvaddch(i, j, 'H');
				break;
			case BLOCK_BODY:
				mvaddch(i, j, 'B');
				break;
			case BLOCK_FRUIT:
				mvaddch(i, j, 'F');
				break;
			case BLOCK_POISON:
				mvaddch(i, j, 'P');
				break;
			case BLOCK_GATE:
				mvaddch(i, j, 'O');
				break;
			case BLOCK_INVISIBLE:
				mvaddch(i, j, ' ');
				break;
			}
		}
	}

	refresh();
}

void GameState::InitGameStateWindow() {
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, max_height, max_width);
}

// 뱀 머리가 있는 블럭 체크
void GameState::ActiveObject() {	
	int y = snake->GetHead().y;
	int x = snake->GetHead().x;
	char block = map->GetBlock(x, y);
	
	switch (block) {
	// 벽이나 몸에 닿은 경우
	case BLOCK_WALL:
		cause_of_death = "< Head hit the wall... >";
		snake->SetDead();
		break;
	case BLOCK_BODY:
		cause_of_death = "< Head hit the body... >";
		snake->SetDead();
		break;
	// 과일 아이템
	case BLOCK_FRUIT:
		item_hdlr->DeleteBlock(y, x);
		mission->SetFruitScore(mission->GetFruitScore()+1);
		snake->SetGrow(true);
		break;
	// 독 아이템
	case BLOCK_POISON:
		item_hdlr->DeleteBlock(y, x);
		mission->SetPoisonScore(mission->GetPoisonScore()+1);
		snake->Shrink();
		break;
	// 게이트
	case BLOCK_GATE:
		Gate pair_gate = gate_hdlr->GetGatePair();
		mission->SetGateScore(mission->GetGateScore()+1);
		gate_hdlr->is_in_use = true;
		snake->SetHeadPos(pair_gate.GetPosition().y, pair_gate.GetPosition().x);
		break;
	}

	if (snake->IsDead()) {
		ChangeState(new GameOverState());
	}
	snake->ApplyBlock();
	
	return;
}

// EOF
