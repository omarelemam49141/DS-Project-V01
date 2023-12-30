#include "ActionAddEllipse.h"
/*#include "..\Figures\CSquare.h"*/
#include "CEllipse.h"

/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
//Omar
void ActionAddEllipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read ellipse data from the user

	pGUI->PrintMessage("New Ellipse: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Ellipse: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();
	//Step 2 - prepare ellipse data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the ellipse
	Point left;
	left.x = P1.x < P2.x ? P1.x : P2.x;
	left.y = P1.y < P2.y ? P1.y : P2.y;

	Point right;
	right.x = P1.x > P2.x ? P1.x : P2.x;
	right.y = P1.y > P2.y ? P1.y : P2.y;

	//Step 3 - Create an ellipse with the parameters read from the user
	//check if exceeding the drawing area
	CFigure* R = new CEllipse(left, right, SqrGfxInfo);
	if (pGUI->ExceedDrawingArea(left.x, left.y, right.x, right.y))
	{
		pGUI->PrintMessage("Shape exceeding the drawing area");
		return;
	}

	//Step 4 - Add the ellipse to the list of figures
	pManager->AddFigure(R);
}
