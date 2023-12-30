#include "ActionChngFillClr.h"

/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionChngFillClr::ActionChngFillClr(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
//Omar
void ActionChngFillClr::Execute()
{
	color FillColors[] = {BLUE, GREEN, YELLOW, RED, BLACK};
	/*color BGColors[] = {GREY, WHITE, LIGHTYELLOW}; */
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->setCrntFillColor(FillColors[rand() % 5]);

	pGUI->PrintMessage("Fill Color changed");
}
