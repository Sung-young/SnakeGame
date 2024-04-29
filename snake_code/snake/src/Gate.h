#ifndef __GATE_H__
#define __GATE_H__

#include "global.h"

class Gate: public BaseObject {
public:
	Position position;

	Gate();
	Gate(Position position);
	~Gate();

	void Update(float tic);
	void Render();

	Position GetPosition();

	void SetPosition(Position position);
	void SetPosition(int x, int y);

	int X();
	int Y();
	bool ComparePosition(int x, int y);
};

#endif

// EOF
