#include "ActionSave.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\GUI.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ActionSave::ActionSave(ApplicationManager* pApp, int FigCount, bool exit = false) : Action(pApp)
{
	FileName = "temp_name";
	FigCnt = FigCount;

}

void ActionSave::ReadActionParameters()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Enter File Name");
	FileName = pGUI->GetSrting();
}

void ActionSave::Execute()
{
	ReadActionParameters();
	GUI* pGUI = pManager->GetGUI();

	ofstream OutFile;
	OutFile.open("saved_Drawing_files\\" + FileName + ".txt", ios::out | ios::trunc);


	//adding UI info to the output
	OutFile << pManager->colorString(pGUI->getCrntDrawColor())
		<< "\t" << pManager->colorString(pGUI->getCrntFillColor())
		<< "\t" << pManager->colorString(pGUI->getCrntBGColor()) << "\n";
	OutFile << FigCnt << "\n";

	pManager->SaveAll(OutFile);
	OutFile.close();
	pGUI->PrintMessage("File Saved!");


}





