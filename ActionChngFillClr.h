#ifndef ACTION_CHNG_FILL_CLR_H
#define ACTION_CHNG_FILL_CLR_H

#include "Actions/Action.h"

//Add ActionChngFillClr Action class
class ActionChngFillClr : public Action
{
public:
	class ActionChngFillClr(ApplicationManager* pApp);

	//Change the fikking color
	void Execute();
};

#endif
