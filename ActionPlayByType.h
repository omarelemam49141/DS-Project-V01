#pragma once
#ifndef ACTION_PLAY_TYPE_H
#define ACTION_PLAY_TYPE_H
#include "Actions/Action.h"

class ActionPlayByType : public Action
{
	int correct;
	int wrong;
public:
	ActionPlayByType(ApplicationManager* pApp);
	void Execute();
};
#endif
