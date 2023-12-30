#include "ActionChngFigureClr.h"
/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionChngFigureClr::ActionChngFigureClr(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
//Omar
void ActionChngFigureClr::Execute()
{
	//get all the selected figures
	int count = pManager->GetCount(); //get the number of figures
	CFigure* fig = NULL;
	GUI* pGUI = pManager->GetGUI();
	for (int i = 0; i < count; i++)// if the figure is selected change its colors
	{
		fig = pManager->GetFigureByIndex(i);//Implemented method to get the next figure
		if (fig->IsSelected())
		{
			fig->ChngDrawClr(listOfColors[rand() % 6]);
			fig->ChngFillClr(listOfColors[rand() % 6]);
			fig->SetSelected(false);
			pManager->UpdateInterface();
			pGUI->PrintMessage("Selected figures colors changed");
		}
	}
	//set their drawing color and their fill color to a new random color
	//unselect them
	//update the interface
	/*color BGColors[] = {GREY, WHITE, LIGHTYELLOW}; */
	//Get a Pointer to the Interface
}

