#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
//asmaa
#include<fstream>
#include "CMUgraphicsLib/colors.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* selectedfigure; //The Selected Figure
	int selectedCount;					//Number of selected figures
	//Pointers to Input and Output classes
	GUI* pGUI;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList

	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window	

	//Omar//getFigureList
	CFigure* GetFigureByIndex(int index);
	//Omar 
	int GetCount();
	//omar
	void DeleteFigureAndRearrange(CFigure* pFig, int index);
	//omar
	bool DeleteSelectedObjects();
	//BringToFront/back
	int ApplicationManager::GetSelectedFigureIndex();
	void ApplicationManager::sendFigToFront(int index);
	void ApplicationManager::sendFigToBack(int index);
	//Asmaa
	void deleteALLFig();
	string colorString(color) const;
	void SaveAll(ofstream& Out);
	color ColorObject(string) const;

	CFigure* GetSelectedFigure() const;

	int GetSelectedCount();



	int ApplicationManager::numberOfShapes();
	string ApplicationManager::getRandomExistingType();
	int ApplicationManager::countByType(string type);
	int ApplicationManager::getFigCount() const;
	CFigure* DrawnFigs(int i) const;
	string ApplicationManager::getRandomExistingColor();
	string ApplicationManager::getColorName(color c);
	int ApplicationManager::countByColor(string color);
	void ApplicationManager::getRandomColorAndType(string& type, string& color);
	int ApplicationManager::countByTypeAndColor(string type, string color);




};

#endif