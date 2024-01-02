#pragma once
#ifndef ACTION_COLORIZE_H
#define ACTION_COLORIZE_H

#include "Actions/Action.h"

//Add ActionDelete Action class
class ActionColorize : public Action
{
private:
	color _clr;

public:
	class ActionColorize(ApplicationManager* pApp, color clr);

	//Change the fikking color
	void Execute();
};

#endif

