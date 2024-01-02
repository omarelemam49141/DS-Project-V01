#include "ActionChngBGClr.h"
/*#include "..\Figures\CSquare.h"*/

/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionChngBGClr::ActionChngBGClr(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
//Omar
void ActionChngBGClr::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->ClearToolBar();
	pGUI->PrintMessage("Choose a background color");
	pGUI->CreateColorToolBar('b');
}
