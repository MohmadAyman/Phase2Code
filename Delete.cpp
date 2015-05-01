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
}
void Delete::Execute()
{
	Output *pOut = pManager->GetOutput();	
	Statement *sel = pManager->GetSelectedStatement();

	if (sel != NULL && sel->IsSelected())
	{
		pManager->DeleteStatement(sel);
		pOut->PrintMessage("you deleted an object");
		pOut->ClearDrawArea();
	}
}