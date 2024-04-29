#include "GateHandler.h"

extern Map *map;
extern Snake *snake;

Gate pair_gate;

GateHandler::GateHandler() {
	NULL;
}

GateHandler::~GateHandler() {
	NULL;
}

// 게이트 페어 전체 업데이트
void GateHandler::Update(float tic) {
	if(is_in_use) {	// 게이트를 통과중
		// 게이트를 나왔다면
		if(IsExitGate()) {
			// 게이트 삭제 후 다시 생성
			DeleteGate();
			SpawnGate(tic);
			is_in_use = false;
		}
		return;
	}
	if (tic - last_drop_time < DROP_GATE_INTERVAL) {
		return;	// 게이트 통과중이 아니면서 게이트 만료인 경우
	}
	if (is_created) {
		DeleteGate();
	} else { // 없으면 생성 (초기에 한 번만 도달함.)
		SpawnGate(tic);
	}	
}

void GateHandler::Render() {
	NULL;
}

// 게이트를 생성할 랜덤한 벽 찾기
Position GateHandler::GetRandomPosition() {
	while (true) {
		int x = rand() % WIDTH;
		int y = rand() % HEIGHT;
		if (map->GetBlock(x, y) == BLOCK_WALL) {
			return Position(x, y);
		}
	}
}

// 게이트 짝을 찾아서 반환
Gate GateHandler::GetGatePair() {
	int pair_x, pair_y;
	char direction;
	bool is_left_space = false;
	bool is_right_space = false;
	bool is_up_space = false;
	bool is_down_space = false;

	// 게이트 페어 찾기
	Gate gate = gate_a;
	if(gate.ComparePosition(snake->GetHead().x, snake->GetHead().y)) {
		pair_x = gate_b.X();
		pair_y = gate_b.Y();
	} else {
		pair_x = gate_a.X();
		pair_y = gate_a.Y();
	}

	// 페어 근처 탐색
	if (map->GetBlock(pair_x, pair_y + 1) == BLOCK_SPACE) {
		is_down_space = true;
	} if (map->GetBlock(pair_x + 1, pair_y) == BLOCK_SPACE) {
		is_right_space = true;
	} if (map->GetBlock(pair_x, pair_y - 1) == BLOCK_SPACE) {
		is_up_space = true;
	} if (map->GetBlock(pair_x - 1, pair_y) == BLOCK_SPACE) {
		is_left_space = true;
	}
	
	// 진입방향과 일치하는 경우
	direction = snake->direction;
	if (is_left_space && (direction == DIR_LEFT)) {
		pair_x -= 1;
	} else if (is_right_space && (direction == DIR_RIGHT)) {
		pair_x += 1;
	} else if (is_up_space && (direction == DIR_UP)) {
		pair_y -= 1;
	} else if (is_down_space && (direction == DIR_DOWN)) {
		pair_y += 1;
	}
	
	// 진행 방향을 바꿔야 하는 경우
	else if (direction == DIR_UP || direction == DIR_DOWN) {
		if (is_left_space){
			pair_x -= 1;
			snake->SetDirection(DIR_LEFT);
		} else if (is_right_space) {
			pair_x += 1;
			snake->SetDirection(DIR_RIGHT);
		} else if (is_up_space) {
			pair_y -= 1;
			snake->SetDirection(DIR_UP);
		} else if (is_down_space) {
			pair_y += 1;
			snake->SetDirection(DIR_DOWN);
		}
	} else if (direction == DIR_LEFT || direction == DIR_RIGHT) {
		if (is_down_space) {
			pair_y += 1;
			snake->SetDirection(DIR_DOWN);
		} else if (is_up_space) {
			pair_y -= 1;
			snake->SetDirection(DIR_UP);
		} else if (is_left_space) {
			pair_x -= 1;
			snake->SetDirection(DIR_LEFT);
		} else if (is_right_space) {
			pair_x += 1;
			snake->SetDirection(DIR_RIGHT);
		}
	}
	// pair_gate와 동기화
	pair_gate.SetPosition(pair_x, pair_y);

	return pair_gate;
}

// 게이트 페어 생성
void GateHandler::SpawnGate(float tic) {
	Gate gate_a_tmp(GetRandomPosition());
	Gate gate_b_tmp(GetRandomPosition());
	
	gate_a = gate_a_tmp;
	gate_b = gate_b_tmp;
	
	ApplyBlock();
	ApplyBlock();

	last_drop_time = tic;
	is_created = true;
}

// 게이트 페어 삭제
void GateHandler::DeleteGate() {
	map->SetBlock(gate_a.GetPosition(), BLOCK_WALL);
	map->SetBlock(gate_b.GetPosition(), BLOCK_WALL);

	is_created = false;
}

// 수동으로 맵 데이터에 적용
void GateHandler::ApplyBlock() {
	map->SetBlock(gate_a.GetPosition(), BLOCK_GATE);
	map->SetBlock(gate_b.GetPosition(), BLOCK_GATE);
}

// 뱀 꼬리가 게이트를 빠져나오는지
bool GateHandler::IsExitGate() {
	Position tail = snake->GetTail();
	return (pair_gate.X() == tail.x && pair_gate.Y() == tail.y);
}


// EOF
