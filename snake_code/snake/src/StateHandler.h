#ifndef __STATE_HANDLER_H__
#define __STATE_HANDLER_H__

#include "global.h"
#include "GameMenuState.h"

using namespace std;

void ExecuteDriver();
void InitState();
void DelayState();
void ExitProcess();

void Update(float tic);
void Render();

void InitGlobalTimer();
float GetTic();
void ChangeState(BaseState* state);



#endif

// EOF
