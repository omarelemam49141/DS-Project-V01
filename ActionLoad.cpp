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
	// Declare variables to store color information
	string drawColor, fillColor, bgColor;
	ifstream File;
	bool flag = false;

	// Declare variables for figure details
	string figName, drawclr, fillclr;
	int figcount;
	// Declare a pointer to CFigure to store loaded figures
	CFigure* fig;

	// Get the GUI instance from the ApplicationManager
	GUI* pGUI = pManager->GetGUI();

	// Ask the user for the file name
	pGUI->PrintMessage("please write the file name -->");
	FileName = pGUI->GetSrting();

	// Open the file for reading
	File.open("saved_Drawing_files/" + FileName + ".txt");

	// Check if the file is opened successfully
	if (File.fail())
	{
		pGUI->PrintMessage("invalid name");
		return;
	}

	// Clear the drawing area and delete all figures in the manager
	pGUI->ClearDrawArea();
	pManager->deleteALLFig();

	// Read the color information from the file
	File >> drawColor >> fillColor >> bgColor;

	// Convert color strings to color objects using ColorObject function
	color CrntDrawClr = pManager->ColorObject(drawColor);
	color CrntFillClr = pManager->ColorObject(fillColor);
	color CrntBGClr = pManager->ColorObject(bgColor);

	// Set the current colors in the GUI
	pGUI->setCrntDrawColor(CrntDrawClr);
	pGUI->setCrntFillColor(CrntFillClr);
	pGUI->setCrntBGColor(CrntBGClr);

	pGUI->ClearDrawArea();

	File >> figcount;

	while (figcount)
	{
		// Read the figure name
		File >> figName;

		// Create a new figure based on the figure name
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
		// Load the figure details from the file
		fig->Load(File);
		pManager->AddFigure(fig);

		// Decrement the figure count
		figcount--;
	}

	// Update the GUI to draw the loaded figures
	pManager->UpdateInterface();    //draw the figure list
	pGUI->PrintMessage("File Loaded.. ^_^");
	pGUI->ClearStatusBar();
}