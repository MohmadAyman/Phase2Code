#include "SmplAssign.h"
#include <sstream>

using namespace std;

SmplAssign::SmplAssign() {}
SmplAssign::SmplAssign(Point Lcorner, string LeftHS, double RightHS)
{
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}
SmplAssign& SmplAssign::operator=(const SmplAssign& copy) {
	this->ID = copy.ID;
	this->Inlet = copy.Inlet;
	this->LeftCorner = copy.LeftCorner;
	this->LHS = copy.LHS;
	this->Outlet = copy.Outlet;
	this->pConn = NULL;
	this->RHS = copy.RHS;
	this->Selected = copy.Selected;
	return *this;
}
SmplAssign::SmplAssign(Point Lcorner,const SmplAssign & s)
{
	LHS = s.LHS;
	RHS = s.RHS;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}
void SmplAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void SmplAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}


void SmplAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 

	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

//This function should be called when LHS or RHS changes
void SmplAssign::UpdateStatementText()
{
	if(LHS=="")	//No left handside ==>statement have no valid text yet
		Text = "    = ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T<<LHS<<" = "<<RHS;	
		Text = T.str();	 
	}
}
bool SmplAssign::Within(Point p) const {
	if (LeftCorner.x < p.x  && p.x < (LeftCorner.x + UI.ASSGN_WDTH) && 
		LeftCorner.y < p.y && p.y < (LeftCorner.y + UI.ASSGN_HI))
		return true;
	return false;
}
void SmplAssign::Move() {
	while (buttonstate() == 1) {
		string l = LHS;
		double d = RHS;
		
	}
}
void SmplAssign::Edit(Input*pIn, Output*pOut)
{
	pOut->PrintMessage("Edit Simple Assignment Statement");
	LHS = pIn->GetString(pOut);
	RHS = pIn->GetValue(pOut);
	UpdateStatementText();
}