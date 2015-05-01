#include "Select.h"
#include "..\ApplicationManager.h"
#include "..\Move.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Select::Select(ApplicationManager *pAppManager):Action(pAppManager)
{}
Select::~Select()
{}
void Select::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();

	pOut->PrintMessage("you selected a statment");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}

void Select::Execute()
{
	ReadActionParameters();
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	pIn->GetPointClicked(Position);
	Statement *s=pManager->GetStatement(Position);
	if (s != nullptr)
	{
		if (s->IsSelected() != true)
		{
			pManager->SetSelectedStatement(s);
			s->SetSelected(true);
			pOut->PrintMessage("you selected a statment");
			if (buttonstate() == 1) {
				//s->Move();
			}
		}
		else
		{
			s->SetSelected(false);
			pOut->PrintMessage("you Unselected a statment");
		}
	}
}