#include "AddSmplAssign.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddSmplAssign::AddSmplAssign(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddSmplAssign::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Simple Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();	
}

void AddSmplAssign::Execute()
{
	ReadActionParameters();
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH/2;
	Corner.y = Position.y ;
	
	SmplAssign *pAssign = new SmplAssign(Corner, "", 0);
	pManager->AddStatement(pAssign);
}
void AddSmplAssign::ExecuteCopy(const Statement &C)
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

//	SmplAssign *pAssign = new SmplAssign(Corner, C);
//	pManager->AddStatement(pAssign);
}
void AddSmplAssign::ExecuteCp(const SmplAssign & C)
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	SmplAssign *pAssign = new SmplAssign(Corner, C);
	pManager->AddStatement(pAssign);
}