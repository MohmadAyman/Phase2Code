#include "MultiSelect.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Actions\Select.h"
MultiSelect::MultiSelect(ApplicationManager *pAppManager) :Action(pAppManager)
{}

MultiSelect::~MultiSelect()
{}
void MultiSelect::ReadActionParameters() {
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();

	pOut->PrintMessage("you selected a statment");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}
void MultiSelect::Execute() {
	ReadActionParameters();
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
		do
		{
			pIn->GetPointClicked(Position);
			Statement *s = pManager->GetStatement(Position);
			if (s != nullptr)
			{
				if (s->IsSelected() != true)
				{
					pManager->SetSelectedStatement(s);
					s->SetSelected(true);
					pOut->PrintMessage("you selected a statment");
				}
				else
				{
					s->SetSelected(false);
					pOut->PrintMessage("you Unselected a statment");
				}
				pManager->UpdateInterface();
			}
		} while (pIn->GetUserAction() != MULTI_SELECT);
}
void MultiSelect::ExecuteCopy(const Statement &) {

}