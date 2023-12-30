#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
class ActionSwitchToPlay : public Action
{
private:
public:
	ActionSwitchToPlay(ApplicationManager* pMan);
	virtual void Execute();

};
#pragma once
