#include "ActionSave.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\GUI.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
//asmaa This action is responsible for saving the current  drawing to a text file.
ActionSave::ActionSave(ApplicationManager* pApp, int FigCount) : Action(pApp)
{
	FileName = "temp_name";
	FigCnt = FigCount;

}

void ActionSave::ReadActionParameters()
{
	//This function reads the file name from the user .
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
	// Open a file for writing
	OutFile.open("saved_Drawing_files\\" + FileName + ".txt", ios::out | ios::trunc);


	//adding UI info to the output
	OutFile << pManager->colorString(pGUI->getCrntDrawColor())
		<< "\t" << pManager->colorString(pGUI->getCrntFillColor())
		<< "\t" << pManager->colorString(pGUI->getCrntBGColor()) << "\n";
	OutFile << FigCnt << "\n";

	// Saving all figures to the file
	pManager->SaveAll(OutFile);

	// Close the file and display a message
	OutFile.close();
	pGUI->PrintMessage("File Saved!");


}





