
#pragma once

#include "Action.h"

class ActionPlayByFillType: public Action
{
	int correct;
	int wrong;
public:
	ActionPlayByFillType(ApplicationManager* pApp);
	void Execute();
};

