#include "ItemHandler.h"

extern Map *map;

ItemHandler::ItemHandler() {
	getmaxyx(stdscr, max_height, max_width);
}

ItemHandler::~ItemHandler() {
	NULL;
}

// item_list들의 상태를 업데이트
void ItemHandler::Update(float tic) {
	// 만료된 아이템들 삭제
	DeleteExpiredItems(tic);

	// 드랍 타임 & 드랍된 아이템 개수 체크
	if (tic - last_drop_time > DROP_ITEM_INTERVAL && item_list.size() < MAX_ITEMS) {
		int rand_num = rand();
		if (rand_num & 0x1) {
			AddItem(ITEM_POISON, tic);
		} else {
			AddItem(ITEM_FRUIT, tic);
		}
		ApplyBlock();
		last_drop_time = tic;
	}
}

void ItemHandler::Render() {
	NULL;
}

// (비멤버 함수) 아이템 만료시간인지 확인
bool IsExceedTime(Item item, float tic) {
	return (tic - item.GetDropType() > DROP_ITEM_EXPIRE);
}

// 아이템을 생성할 랜덤한 공간 찾기
Position ItemHandler::GetRandomPosition() {
	int x, y;
	while (true) {
		x = rand() % WIDTH;
		y = rand() % HEIGHT;
		if (map->GetBlock(x, y) == BLOCK_SPACE) {
			return Position(x, y);
		}
	}
}

// item_list에 아이템 추가
void ItemHandler::AddItem(char item_type, float tic) {
	Position rand_position = GetRandomPosition();
	item_list.push_back(Item(item_type, rand_position, tic));
}

// 시간이 만료된 아이템을 맵과 item_list에서 삭제
void ItemHandler::DeleteExpiredItems(float tic) {
	Item item;
	// item_list들의 상태를 체크하기 위한 임시 변수
	vector<int> expired_item_index;

	// 만료된 아이템을 맵과 item_list에서 삭제
	for (int idx = 0; idx < item_list.size(); idx++) {
		item = item_list[idx];
		if (IsExceedTime(item, tic)) {
			map->DeleteBlock(item.Y(), item.X());
			item_list.erase(item_list.begin() + idx);
		}
	}
}

// 아이템을 item_list에서 삭제
void ItemHandler::DeleteBlock(int y, int x) {
	Item item;
	int delete_index;
	for (int i = 0; i < item_list.size(); i++) {
		item = item_list[i];
		if (item.ComparePosition(x, y)) {
			delete_index = i;
		}
	}
	item_list.erase(item_list.begin() + delete_index);
}

// 아이템을 맵의 블록에 적용
void ItemHandler::ApplyBlock() {
	int x, y;
	char item_type;
	Item item;
	for (int i = 0; i < item_list.size(); i++) {
		item = item_list[i];
		x = item.X();
		y = item.Y();
		item_type = item.GetType();

		map->SetBlock(y, x, item_type);
	}
}

// EOF
