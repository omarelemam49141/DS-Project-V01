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
	/*color DrawColors[] = {BLUE, GREEN, YELLOW, RED, BLACK}; */
	/*color FillColors[] = {BLUE, GREEN, YELLOW, RED, BLACK};*/
	color BGColors[] = { GREY, WHITE, LIGHTYELLOW, LIGHTBLUE, LIGHTCYAN, LIGHTGOLDENRODYELLOW };
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->setCrntBGColor(BGColors[rand() % 6]);
	
	pGUI->ClearDrawArea();

	pGUI->PrintMessage("BG Color changed");
}
