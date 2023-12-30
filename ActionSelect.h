#ifndef ACTION_SELECT_CLR_H
#define ACTION_SELECT_CLR_H

#include "Actions/Action.h"

//Add ActionChngFillClr Action class
class ActionSelect : public Action
{
public:
	class ActionSelect(ApplicationManager* pApp);

	//Change the fikking color
	void Execute();
};

#endif