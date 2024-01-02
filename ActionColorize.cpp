#include "ActionColorize.h"
/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionColorize::ActionColorize(ApplicationManager* pApp, color clr) : Action(pApp)
{
	_clr = clr;
}

void ActionColorize::Execute() {
	GUI* pGui = pManager->GetGUI();
	pGui->ChangeColors(_clr);
	pGui->PrintMessage("Color changed to " + pManager->colorString(_clr));
	pGui->ClearToolBar();
	pGui->CreateDrawToolBar();
}