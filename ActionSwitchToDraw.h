#ifndef ACTION_SWITCH_TO_DRAW_MODE_H
#define ACTION_SWITCH_TO_DRAW_MODE_H
#include "Actions/Action.h"

//Add Switch to draw mode Action class
class ActionSwitchToDraw : public Action
{
public:
	ActionSwitchToDraw(ApplicationManager* pApp);

	virtual void Execute();

};

#endif#pragma once
