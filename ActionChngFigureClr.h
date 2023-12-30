#ifndef ACTION_CHNG_FIGURE_CLR_H
#define ACTION_CHNG_FIGURE_CLR_H

#include "Actions/Action.h"

//Add ActionChngFillClr Action class
class ActionChngFigureClr : public Action
{

	color listOfColors[6] = {BLUE, GREEN, RED, BLACK, ORANGE, BROWN};

public:
	class ActionChngFigureClr(ApplicationManager* pApp);

	//Change the fikking color
	void Execute();
};

#endif