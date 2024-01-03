#ifndef CHEXAGON_H
#define CHEXAGON_H
#endif

#include "figures/CFigure.h"
#include <vector>

class CHexagon : public CFigure
{
private:
	int * xCoordinates;
	int* yCoordinates;
	std::vector<int> originalXCoordinates;
	std::vector<int> originalYCoordinates;
	int vertexes;
public:
	CHexagon(int *, int*, int, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void DrawMe(GUI* pOut) const;
	bool IsPointInside(int x, int y);
	virtual string GetInfo();
	//asma
	virtual void Save(ofstream&);
	virtual void Load(ifstream&);
	//nyra
	void ResetToOriginalSize();
	virtual void CHexagon::Resize(GUI* pGUI, float scaleFactor);
	string CHexagon::getShapeType();
};
