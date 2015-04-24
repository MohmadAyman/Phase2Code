#include "Delete.h"
#include "C:\Users\MohmadAyman\Documents\CMP103 Project S2015 - ALL Docs - student\Project Framework\Actions\Action.h"
#include "C:\Users\MohmadAyman\Documents\CMP103 Project S2015 - ALL Docs - student\Project Framework\ApplicationManager.h"
#include "C:\Users\MohmadAyman\Documents\CMP103 Project S2015 - ALL Docs - student\Project Framework\GUI\input.h"
#include "C:\Users\MohmadAyman\Documents\CMP103 Project S2015 - ALL Docs - student\Project Framework\GUI\Output.h"

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