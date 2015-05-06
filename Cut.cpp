#include "Cut.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI/input.h"
#include "GUI/Output.h"
#include "Actions\AddSmplAssign.h"


Cut::Cut(ApplicationManager*app) :Action(app)
{}


Cut::~Cut()
{}

void Cut::ReadActionParameters() {}
void Cut::Execute() {
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	//Statement** Allselected = pManager->GetAllSelectedStatements();
	Statement *s = pManager->GetSelectedStatement();
	int i = 0;
	if (s != nullptr)
	{
		pIn->GetPointClicked(Position);
		const SmplAssign *l = dynamic_cast<SmplAssign*>(s);//Allselected[i]); /// Conditional and connectors to be added
		if (l != NULL)
		{
			AddSmplAssign *pAct = NULL;
			pAct = new AddSmplAssign(pManager);
			pAct->ExecuteCp(*l);
		}
		//	i++;
		pManager->DeleteStatement(s);
		pOut->ClearDrawArea();
	}
}
void Cut::ExecuteCopy(const Statement &) {}
