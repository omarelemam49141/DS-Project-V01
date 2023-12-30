#include "ActionSendToFront.h"
/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionSendToFront::ActionSendToFront(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
//Omar
void ActionSendToFront::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int selectedFigIndex = pManager->GetSelectedFigureIndex();//if no object is selected return -1

	if (selectedFigIndex == -1)
	{
		pGUI->PrintMessage("You must select any figure first");
		return;
	}

	pManager->sendFigToFront(selectedFigIndex);


	pGUI->ClearDrawArea();
	pManager->UpdateInterface();
}
