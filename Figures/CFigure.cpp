#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

CFigure::CFigure() {

}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

//asmaa
string CFigure::ColorString(color ClrObj) const  //Convert from Color Type to String Type
{
	if (ClrObj == WHITE) return "WHITE";
	else if (ClrObj == BLACK) return "BLACK";
	else if (ClrObj == BROWN) return "BROWN";
	else if (ClrObj == PURPLE) return "PURPLE";
	else if (ClrObj == PINK) return "PINK";
	else if (ClrObj == RED) return "RED";
	else if (ClrObj == ORANGE) return "ORANGE";
	else if (ClrObj == YELLOW) return "YELLOW";
	else if (ClrObj == GREEN) return "GREEN";
	else if (ClrObj == BLUE) return "BLUE";
	else return "GREEN";
}

color CFigure::ColorObject(string ClrStr) const  //Convert from string to color object
{
	if (ClrStr == "WHITE") return WHITE;
	else if (ClrStr == "BLACK") return BLACK;
	else if (ClrStr == "BROWN") return BROWN;
	else if (ClrStr == "PURPLE") return PURPLE;
	else if (ClrStr == "PINK") return PINK;
	else if (ClrStr == "RED") return RED;
	else if (ClrStr == "ORANGE") return ORANGE;
	else if (ClrStr == "YELLOW") return YELLOW;
	else if (ClrStr == "GREEN") return GREEN;
	else if (ClrStr == "BLUE") return BLUE;
	else return BLUE;
}
bool CFigure::IsHidden() {
	return FigGfxInfo.IsHidden;
};
void CFigure::show() {
	FigGfxInfo.IsHidden = false;
};