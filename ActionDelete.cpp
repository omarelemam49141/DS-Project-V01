#include "ActionDelete.h"
/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
//Omar
void ActionDelete::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	bool selected = pManager->DeleteSelectedObjects();//if no object is selected return false

	if (!selected)
	{
		pGUI->PrintMessage("You must select any figure first");
		return;
	}

	pGUI->ClearDrawArea();
	pManager->UpdateInterface();
}
