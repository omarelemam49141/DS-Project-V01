#include "CHexagon.h"
#include <iostream>
#include <fstream>
using namespace std;
CHexagon::CHexagon(int *_xCoords, int* _yCoords, int _vertexes, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
    xCoordinates = _xCoords;
    yCoordinates = _yCoords;
	vertexes = _vertexes;
}

CHexagon::CHexagon() {
    xCoordinates = new int[6];
    yCoordinates = new int[6];
    vertexes = 6;
}


void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawHexagon to draw a hexagon on the screen	
	pGUI->DrawHexagon(xCoordinates, yCoordinates, vertexes, FigGfxInfo, Selected);
}

bool CHexagon::IsPointInside(int x, int y)
{
    // Check if the point is within the bounding box of the hexagon
    int minX = *std::min_element(xCoordinates, xCoordinates + vertexes);
    int maxX = *std::max_element(xCoordinates, xCoordinates + vertexes);
    int minY = *std::min_element(yCoordinates, yCoordinates + vertexes);
    int maxY = *std::max_element(yCoordinates, yCoordinates + vertexes);

    if (x < minX || x > maxX || y < minY || y > maxY) {
        return false;  // The point is outside the bounding box
    }

    // Check if the point is inside the hexagon using a ray-casting algorithm
    int crossings = 0;
    for (int i = 0; i < vertexes; ++i) {
        int x1 = xCoordinates[i];
        int y1 = yCoordinates[i];
        int x2 = xCoordinates[(i + 1) % vertexes];
        int y2 = yCoordinates[(i + 1) % vertexes];

        if (((y1 <= y && y < y2) || (y2 <= y && y < y1)) &&
            x < (x2 - x1) * (y - y1) / (y2 - y1) + x1) {
            crossings++;
        }
    }

    // If the number of crossings is odd, the point is inside the hexagon
    return (crossings % 2 == 1);
}

string CHexagon::GetInfo()
{
    return "First point: (" + to_string(xCoordinates[0]) + ", " + to_string(yCoordinates[0]) + ")" +
        " - Second point: (" + to_string(xCoordinates[1]) + ", " + to_string(yCoordinates[1]) + ")"
        + " - vertexes count is: " + to_string(vertexes);
}

//asma save
void CHexagon::Save(ofstream& OutFile) {
    OutFile << "CHexagon\t";
    OutFile << this->vertexes << "\t";
    for (int i = 0; i < vertexes; i++) {
        OutFile << this->yCoordinates[i] << "\t";
    }
    for (int i = 0; i < vertexes; i++) {
        OutFile << this->xCoordinates[i] << "\t";
    }

    OutFile << ColorString(this->FigGfxInfo.DrawClr) << "\t";



    if (this->FigGfxInfo.isFilled)
        OutFile << this->ColorString(this->FigGfxInfo.FillClr) << "\n";
    else
        OutFile << "NO_FILL\n";
}

void CHexagon::Load(ifstream& Infile) {
    string hexagonData;
    Infile >> vertexes;
    yCoordinates = new int[vertexes];
    xCoordinates = new int[vertexes];
    for (int i = 0; i < vertexes; i++) {
        Infile >> yCoordinates[i];
    }
    for (int i = 0; i < vertexes; i++) {
        Infile >> xCoordinates[i];
    }

    Infile >> hexagonData;
    FigGfxInfo.DrawClr = ColorObject(hexagonData);

    Infile >> hexagonData;
    FigGfxInfo.FillClr = ColorObject(hexagonData);
    FigGfxInfo.isFilled = true;

    this->show();
    this->FigGfxInfo.BorderWdth = 3; //pass 3 as default value for borderWidth
    this->SetSelected(false);
}

//nyra
void CHexagon::Resize(GUI* pGUI, float scaleFactor)
{
    // Calculate the center of the hexagon
    float centerX = 0, centerY = 0;
    for (int i = 0; i < vertexes; ++i) {
        centerX += xCoordinates[i];
        centerY += yCoordinates[i];
    }
    centerX /= vertexes;
    centerY /= vertexes;

    // Check if the resized hexagon would be outside the drawing area
    for (int i = 0; i < vertexes; ++i) {
        float dx = xCoordinates[i] - centerX;
        float dy = yCoordinates[i] - centerY;

        // Calculate the new position after resizing
        int newX = static_cast<int>(centerX + scaleFactor * dx);
        int newY = static_cast<int>(centerY + scaleFactor * dy);

        // Check if the new position is outside the drawing area
        if (newX < 0 || newX > UI.width ||
            newY < UI.ToolBarHeight ||
            newY > UI.height - UI.StatusBarHeight) {
            pGUI->PrintMessage("Resizing hexagon exceeds drawing area or is very small");
            return;  // Abort resizing
        }
    }

    // If all vertices are within the drawing area, apply the resizing
    for (int i = 0; i < vertexes; ++i) {
        float dx = xCoordinates[i] - centerX;
        float dy = yCoordinates[i] - centerY;

        // Resize the distance from the center by the scale factor
        xCoordinates[i] = static_cast<int>(centerX + scaleFactor * dx);
        yCoordinates[i] = static_cast<int>(centerY + scaleFactor * dy);
    }
}

void CHexagon::ResetToOriginalSize()
{
    for (int i = 0; i < vertexes; ++i) {
        xCoordinates[i] = originalXCoordinates[i];
        yCoordinates[i] = originalYCoordinates[i];
    }
}
