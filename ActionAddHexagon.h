#ifndef ACTION_ADD_Hexagon_H
#define ACTION_ADD_Hexagon_H

#include "Actions/Action.h"

//Add Square Action class
class ActionAddHexagon : public Action
{
public:
	ActionAddHexagon(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();
};

#endif
