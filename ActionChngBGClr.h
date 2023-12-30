#ifndef ACTION_CHNG_BG_CLR_H
#define ACTION_CHNG_BG_CLR_H

#include "Actions/Action.h"

//Add ActionChngBGClr Action class
class ActionChngBGClr : public Action
{
public:
	class ActionChngBGClr(ApplicationManager* pApp);

	//Change the drawing color
	void Execute();
};

#endif

