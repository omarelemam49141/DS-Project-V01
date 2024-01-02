#include "ActionChngDrawClr.h"
/*#include "..\Figures\CSquare.h"*/
#include "CEllipse.h"

/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionChngDrawClr::ActionChngDrawClr(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
//Omar
void ActionChngDrawClr::Execute()
{
	/*color FillColors[] = {BLUE, GREEN, YELLOW, RED, BLACK};
	color BGColors[] = { GREY, WHITE, LIGHTYELLOW };*/
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar();
	pGUI->PrintMessage("Choose a border color");
	pGUI->CreateColorToolBar('d');
}
