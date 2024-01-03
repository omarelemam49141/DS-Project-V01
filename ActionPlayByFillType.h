#pragma once
#include "Actions/Action.h"

class ActionPlayByFillType : public Action
{
	int correct;
	int wrong;
public:
	ActionPlayByFillType(ApplicationManager* pApp);
	void Execute();
};

