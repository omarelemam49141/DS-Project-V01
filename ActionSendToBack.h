#ifndef ACTION_ActionSendToBack_H
#define ACTION_ActionSendToBack_H

#include "Actions/Action.h"

//Add ActionChngFillClr Action class
class ActionSendToBack : public Action
{
public:
	class ActionSendToBack(ApplicationManager* pApp);

	//Change the fikking color
	void Execute();
};

#endif