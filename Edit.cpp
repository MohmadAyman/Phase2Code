#include "Edit.h"


Edit::Edit(ApplicationManager *pAppManager) :Action(pAppManager)
{}


Edit::~Edit()
{}
void Edit::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();

	pOut->PrintMessage("Edittibg a Statment");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}
void Edit::Execute()
{
	ReadActionParameters();


}
