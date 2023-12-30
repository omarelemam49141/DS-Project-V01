#include "ActionLoad.h"
#include "ApplicationManager.h"
#include "GUI\GUI.h"
#include "Figures\CFigure.h"
#include "Figures\CSquare.h"
#include "CHexagon.h"
#include "CEllipse.h"
#include <fstream>
#include <iostream>

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionLoad::Execute()
{
	string r, g, b;
	ifstream File;
	bool flag = false;
	string figName, drawclr, fillclr;
	int figcount;
	CFigure* fig;
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("please write the file name -->");
	FileName = pGUI->GetSrting();

	File.open("saved_Drawing_files/" + FileName + ".txt");


	if (File.fail())
	{
		pGUI->PrintMessage("invalid name");
		return;
	}
	pGUI->ClearDrawArea();
	pManager->deleteALLFig();

	File >> r >> g >> b;
	//hello
	color CrntDrawClr = pManager->ColorObject(r);
	color CrntFillClr = pManager->ColorObject(g);
	color CrntBGClr = pManager->ColorObject(b);

	pGUI->setCrntDrawColor(CrntDrawClr);
	pGUI->setCrntFillColor(CrntFillClr);
	pGUI->setCrntBGColor(CrntBGClr);

	pGUI->ClearDrawArea();

	File >> figcount;

	while (figcount)
	{
		File >> figName;

		if (figName == "CEllipse")
		{
			fig = new CEllipse();
		}
		else if (figName == "CSquare") {
			fig = new CSquare();
		}

		else if (figName == "CHexagon") {
			fig = new CHexagon();
		}

		fig->Load(File);
		pManager->AddFigure(fig);

		figcount--;
	}
	pManager->UpdateInterface();    //draw the figure list
	pGUI->PrintMessage("File Loaded.. ^_^");
	pGUI->ClearStatusBar();
}