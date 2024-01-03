#include "CSquare.h"
#include <iostream>
#include <fstream>
using namespace std;

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner.x = P1.x;
	TopLeftCorner.y = P1.y;
	length = len;
}
	
CSquare::CSquare(){
	TopLeftCorner = {};
	length = 1;
}

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
}

//omar
bool CSquare::IsPointInside(int x, int y)
{
	// Check if the point is within the bounds of the square
	return (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length &&
		y >= TopLeftCorner.y && y <= TopLeftCorner.y + length);
}

//omar return the details
string CSquare::GetInfo()
{
	return "First point: (" + to_string(TopLeftCorner.x) + ", " + to_string(TopLeftCorner.y) + ")" + " - side length is: " + to_string(length);
}

//asma save This function writes the details of the ellipse figure to the output file stream (OutFile).
void CSquare::Save(ofstream& OutFile) {

	cout << "i get called";
	//the type of the figure
	OutFile << "CSquare\t"
		//the coordinates of the two points 
		<< this->TopLeftCorner.x << "\t"
		<< this->TopLeftCorner.y << "\t"
		<< this->length << "\t"

		// the drawing color
		<< this->ColorString(this->FigGfxInfo.DrawClr) << "\t";
	//the fill color
	if (this->FigGfxInfo.isFilled)
		OutFile << this->ColorString(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NO_FILL\n";
}

//asmaa
//This function reads the details of the ellipse figure from the input file stream 
void CSquare::Load(ifstream& Infile) {

	string squareData;

	//// It reads the coordinates of the point and length
	Infile
		>> TopLeftCorner.x
		>> TopLeftCorner.y
		>> length;

	// the drawing color
	Infile >> squareData;
	FigGfxInfo.DrawClr = this->ColorObject(squareData);

	Infile >> squareData;

	//and the fill color
	FigGfxInfo.FillClr = this->ColorObject(squareData);
	FigGfxInfo.isFilled = true;

	//show figure
	this->show();
	this->FigGfxInfo.BorderWdth = 3; //pass 3 as default value for borderWidth
	this->SetSelected(false);

}

//nyra
void CSquare::Resize(GUI* pGUI, float size) {
	if (this == nullptr) {
		pGUI->PrintMessage("Error: 'this' pointer is null in CSquare::Resize");
		return;
	}

	Point test1 = TopLeftCorner;




	// Calculate the new length after resizing
	float newLength = this->length * size;

	// Check if the square will be outside the drawing area vertically or horizontally
	if (test1.y < UI.ToolBarHeight || test1.x > UI.width || (test1.x - newLength / 2) < 0 || (test1.y - newLength / 2) < UI.ToolBarHeight) {
		pGUI->PrintMessage("Resizing square would place it outside the drawing area or make it too small");
		return;
	}

	// Resize the square by updating its length
	this->length = newLength;
}


string CSquare::getShapeType()
{
	return "Square";
}
