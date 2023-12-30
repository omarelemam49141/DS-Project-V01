#include <algorithm>
#include <cmath>
#include "ActionAddHexagon.h"
/*#include "..\Figures\CSquare.h"*/

/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

#include "CHexagon.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
//Omar
void ActionAddHexagon::Execute()
{
    int xCoords[2], yCoords[2];
    int vertexes = 6;

    // Get a Pointer to the Interface
    GUI* pGUI = pManager->GetGUI();

    GfxInfo HexGfxInfo;
    HexGfxInfo.isFilled = true;    // default is not filled
    // get drawing, filling colors and pen width from the interface
    HexGfxInfo.DrawClr = pGUI->getCrntDrawColor();
    HexGfxInfo.FillClr = pGUI->getCrntFillColor();
    HexGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

    // Step 1 - Read hexagon data from the user
    for (int i = 0; i < 2; i++)
    {
        pGUI->PrintMessage("New Hexagon: Click at point " + to_string(i + 1));
        // Read point and store in arrays xCoords and yCoords
        pGUI->GetPointClicked(xCoords[i], yCoords[i]);
    }

    pGUI->ClearStatusBar();

    // Step 2 - Prepare hexagon data
    int centerX = (xCoords[0] + xCoords[1]) / 2;
    int centerY = (yCoords[0] + yCoords[1]) / 2;

    int* modifiedXCoords = new int[vertexes];
    int* modifiedYCoords = new int[vertexes];

    // Assuming you want to create a regular hexagon with equal side lengths
    double angleIncrement = 2 * (22/7) / vertexes;
    double radius = sqrt(pow(xCoords[0] - centerX, 2) + pow(yCoords[0] - centerY, 2));

    for (int i = 0; i < vertexes; i++) {
        modifiedXCoords[i] = centerX + radius * cos(i * angleIncrement);
        modifiedYCoords[i] = centerY + radius * sin(i * angleIncrement);
    }

    // Step 3 - Create a hexagon with the parameters read from the user
    CFigure* hexagon = new CHexagon(modifiedXCoords, modifiedYCoords, vertexes, HexGfxInfo);

    // Step 3.1 - Determine the bounding box of the hexagon
    int minX = *min_element(modifiedXCoords, modifiedXCoords + vertexes);
    int minY = *min_element(modifiedYCoords, modifiedYCoords + vertexes);
    int maxX = *max_element(modifiedXCoords, modifiedXCoords + vertexes);
    int maxY = *max_element(modifiedYCoords, modifiedYCoords + vertexes);

    // Step 3.2 - Check if the hexagon exceeds the drawing area
    if (pGUI->ExceedDrawingArea(minX, minY, maxX, maxY))
    {
        pGUI->PrintMessage("Hexagon exceeds the drawing area");
        delete hexagon; // Clean up memory before returning
        return;
    }

    // Step 4 - Add the hexagon to the list of figures
    pManager->AddFigure(hexagon);
}

