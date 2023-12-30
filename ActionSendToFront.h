#ifndef ACTION_ActionSendToFront_H
#define ACTION_ActionSendToFront_H

#include "Actions/Action.h"

class ActionSendToFront : public Action
{
public:
	class ActionSendToFront(ApplicationManager* pApp);

	//Change the fikking color
	void Execute();
};

#endif