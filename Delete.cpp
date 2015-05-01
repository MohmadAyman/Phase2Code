#include "Delete.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI/input.h"
#include "GUI/Output.h"

Delete::Delete(ApplicationManager*pAppManager) :Action(pAppManager)
{}


Delete::~Delete()
{}
void Delete::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();

	pOut->PrintMessage("you are now delted sth");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}
void Delete::Execute()
{
	ReadActionParameters();
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	pIn->GetPointClicked(Position);
	Statement *sel = pManager->GetSelectedStatement();
	if (sel != NULL)
	{
		pManager->DeleteStatement(sel);
		pOut->PrintMessage("you deleted an object");
		pOut->ClearDrawArea();
	}
}