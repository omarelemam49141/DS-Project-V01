#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	CSquare();
	virtual void DrawMe(GUI* pOut) const;
	//omar
	bool IsPointInside(int x, int y);
	//omar
	virtual string GetInfo();
	//asma
	virtual void Save(ofstream&);
	virtual void Load(ifstream&);
	//nyra
	virtual void Resize(GUI* pGUI, float size);
	string CSquare::getShapeType();
};

#endif