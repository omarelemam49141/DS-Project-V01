#ifndef ACTION_CHNG_DRAW_CLR_H
#define ACTION_CHNG_DRAW_CLR_H

#include "Actions/Action.h"

//Add ActionChngDrawClr Action class
class ActionChngDrawClr : public Action
{
public:
	class ActionChngDrawClr(ApplicationManager* pApp);

	//Change the drawing color
	void Execute();
};

#endif
