#ifndef ACTION_RESIZE_H
#define ACTION_RESIZE_H_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"



class ActionResize : public Action
{
private:
	float resizeFactor;
	CFigure* Selected = NULL;

public:
	ActionResize(ApplicationManager* pApp, CFigure* shape, float factor);
	virtual void Execute();
};
#endif
