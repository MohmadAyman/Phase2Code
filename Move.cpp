#include "Move.h"
#include "C:\Users\MohmadAyman\Documents\CMP103 Project S2015 - ALL Docs - student\Project Framework\ApplicationManager.h"
#include "C:\Users\MohmadAyman\Documents\CMP103 Project S2015 - ALL Docs - student\Project Framework\GUI\input.h"
#include "C:\Users\MohmadAyman\Documents\CMP103 Project S2015 - ALL Docs - student\Project Framework\GUI\Output.h"
#include <sstream>
#include "SmplAssign.h"
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Move::Move(ApplicationManager *pAppManager) :Action(pAppManager)
{}

void Move::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("you are moving an object");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}
void Move::Execute()
{
	ReadActionParameters();
	//Calculating left corner of assignement statement block
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	Statement *s;
	s=pManager->GetSelectedStatement();
	pIn->GetPointClicked(Position);
	Point p = Position;
	if (s != nullptr)
	{
		pOut->Dragging(Position);
	}
}
Move::~Move()
{}
void Move::ExecuteCopy(const Statement &) {}