#ifndef ACTION_SAVE
#define ACTION_SAVE

#include "Actions/Action.h"
#include"ApplicationManager.h"
#include"Figures\CFigure.h"
#include "GUI\GUI.h"
#include<fstream>
#include <string>
#include<iostream>
using namespace std;

class ActionSave : public Action
{
private:
	string FileName;
	int FigCnt;
	bool fireExit;
public:
	ActionSave(ApplicationManager* pApp, int FigCount, bool exit);
	virtual void ReadActionParameters();
	virtual void Execute();
	color ColorObject(string ClrStr) const;
};


#endif
