#ifndef __GATE_HANDLER_H__
#define __GATE_HANDLER_H__

#include "global.h"
#include "Gate.h"
#include "Map.h"

class GateHandler: public BaseObject {
public:
	Gate gate_a;
	Gate gate_b;
	
	bool is_created = false;
	bool is_in_use = false;
	float last_drop_time = 0;

	GateHandler();
	~GateHandler();

	void Update(float tic);
	void Render();

	Position GetRandomPosition();
	Gate GetGatePair();
	void SpawnGate(float tic);
	void DeleteGate();
	void ApplyBlock();
	bool IsExitGate();
};

#endif

// EOF
