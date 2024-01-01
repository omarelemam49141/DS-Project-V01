#include "CEllipse.h"
#include <iostream>
#include <fstream>
using namespace std;

CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	pointone = P1;
	pointtwo = P2;
}

CEllipse::CEllipse() {
	pointone = {};
	pointtwo = {};
}

void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::Draw Ellipse	
	pGUI->DrawEllipse(pointone, pointtwo, FigGfxInfo, Selected);
}

bool CEllipse::IsPointInside(int x, int y)
{
    // Calculate the normalized coordinates relative to the center
    double normalizedX = (x - (pointone.x + pointtwo.x) / 2.0) / ((pointtwo.x - pointone.x) / 2.0);
    double normalizedY = (y - (pointone.y + pointtwo.y) / 2.0) / ((pointtwo.y - pointone.y) / 2.0);

    // Check if the point satisfies the ellipse equation
    return (normalizedX * normalizedX + normalizedY * normalizedY) <= 1.0;
}

string CEllipse::GetInfo()
{
    return "First point: (" + to_string(pointone.x) + ", " + to_string(pointone.y) + ")" + 
        " - Second point: (" + to_string(pointtwo.x) + ", " + to_string(pointtwo.y) + ")";
}

//asma save
void CEllipse::Save(ofstream& OutFile) {

	OutFile << "CEllipse\t"
		<< this->pointone.x << "\t"
		<< this->pointone.y << "\t"
		<< this->pointtwo.x << "\t"
		<< this->pointtwo.y << "\t"
		<< this->ColorString(this->FigGfxInfo.DrawClr) << "\t";
	// check figure is filled or not
	if (this->FigGfxInfo.isFilled)
		OutFile << this->ColorString(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NO_FILL\n";
}
void CEllipse::Load(ifstream& Infile) {
	string ellipseData;
	Infile >> pointone.x
		>> pointone.y
		>> pointtwo.x
		>> pointtwo.y;

	Infile >> ellipseData;
	FigGfxInfo.DrawClr = this->ColorObject(ellipseData);

	Infile >> ellipseData;
	FigGfxInfo.FillClr = this->ColorObject(ellipseData);
	FigGfxInfo.isFilled = true;

	this->show();
	this->FigGfxInfo.BorderWdth = 3;
	this->SetSelected(false);
}

//nyra
void CEllipse::Resize(GUI* pGUI, float size) {
    Point test1 = pointone, test2 = pointtwo;

    // Define a tolerance for floating-point comparisons
    const float tolerance = 1e-6;

    // Adjust the size if it matches one of the special cases
    if (std::abs(size - 0.5) < tolerance) size = -0.5;
    else if (std::abs(size - 0.25) < tolerance) size = -(4.0 / 3);
    else if (std::abs(size - 2.0) < tolerance) size = 1.0;
    else if (std::abs(size - 1.0) < tolerance) size = 3.0;

    // Calculate half radius (horizontal x && vertical y)
    float deltaX = 0.5 * (pointtwo.x - pointone.x);
    float deltaY = 0.5 * (pointtwo.y - pointone.y);

    // Calculate resized points
    test1.x -= deltaX * size;
    test2.x += deltaX * size;
    test1.y -= deltaY * size;
    test2.y += deltaY * size;

    // Check if the resized ellipse is within the drawing area
    if (test1.y < UI.ToolBarHeight || test2.y > UI.height - UI.StatusBarHeight
        || test2.x > UI.width || test1.x < 1) {
        pGUI->PrintMessage("Resizing ellipse would place it outside the drawing area");
        return;
    }
    // Check if the resized ellipse is too small
   /* else if (((test2.x - test1.x) / 2) < 1 || ((test2.y - test1.y) / 2) < 1) {
        pGUI->PrintMessage("Resizing ellipse would make it very small");
        return;
    }*/

    // Apply the resized points if no issues
    pointone = test1;
    pointtwo = test2;
}

//omar return the details

string CEllipse::getShapeType()
{
    return "Ellipse";
}