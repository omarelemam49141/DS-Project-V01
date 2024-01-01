#include "ActionSwitchToPlay.h"
// #include "ActionSave.h"
// #include "ActionLoad.h"
#include "GUI\GUI.h"
#include "ApplicationManager.h"

ActionSwitchToPlay::ActionSwitchToPlay(ApplicationManager* pMan) :Action(pMan)
{

}

void ActionSwitchToPlay::Execute() {

	GUI* pGUI = pManager->GetGUI();
	Action* pAct = pManager->CreateAction(SAVE);
	pManager->ExecuteAction(pAct);
	pGUI->ClearToolBar();
	pGUI->CreatePlayToolBar();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Welcome to play mode :)");

}