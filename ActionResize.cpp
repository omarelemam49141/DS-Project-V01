#include "ActionResize.h"
/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionResize::ActionResize(ApplicationManager* pApp, CFigure* selected, float factor) : Action(pApp)
{
	resizeFactor = factor;

}

void ActionResize::Execute() {


	GUI* pGui = pManager->GetGUI();
	int selectedIndex = pManager->GetSelectedFigureIndex();
	if (selectedIndex != -1 && pManager->GetSelectedCount() == 1)
	{
		Selected = pManager->GetSelectedFigure();
		Selected->Resize(pGui, resizeFactor);
		pGui->ClearDrawArea();
		pManager->UpdateInterface();

	}
	else
		pGui->PrintMessage("Select a Figure before you can perform this action, and Only One Figure");
}