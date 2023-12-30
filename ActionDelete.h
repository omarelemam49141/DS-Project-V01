#ifndef ACTION_DELETE_H
#define ACTION_DELETE_H

#include "Actions/Action.h"

//Add ActionDelete Action class
class ActionDelete : public Action
{
public:
	class ActionDelete(ApplicationManager* pApp);

	//Change the fikking color
	void Execute();
};

#endif
