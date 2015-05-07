#include "Copy.h"
#include "SmplAssign.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "Actions\AddSmplAssign.h"
#include "GUI\Output.h"
#include <sstream>


Copy::Copy(ApplicationManager*pAppManger) :Action(pAppManger)
{}


Copy::~Copy()
{}

void Copy::ReadActionParameters() {

}
void Copy::Execute() {
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	//Statement** Allselected = pManager->GetAllSelectedStatements();
	Statement *s = pManager->GetSelectedStatement();
	int i = 0;
	if (s!=nullptr)
	{
			pIn->GetPointClicked(Position);
			const SmplAssign *l = dynamic_cast<SmplAssign*>(s);//Allselected[i]); /// Conditional and connectors to be added
			if (l != NULL)
			{
				AddSmplAssign *pAct = NULL;
				pAct = new AddSmplAssign(pManager);
				pAct->ExecuteCp(*l);	
				delete pAct;
			}
	//	i++;
	}
}
void Copy::ExecuteCopy(const Statement &) {}