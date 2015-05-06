#ifndef SMPL_ASSIGN_H
#define SMPL_ASSIGN_H

#include "Statement.h"

//Simple Assignment statement class
//The simple assignment statement assigns a variable to a value
class SmplAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	double RHS;	//Right Handside (Value)

	Connector *pConn;	//Simple Assignment Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	
public:
	SmplAssign(Point Lcorner, string LeftHS="", double RightHS=0);
	SmplAssign(Point Lcorner,const SmplAssign&);
	SmplAssign(const SmplAssign & s);
	SmplAssign& SmplAssign::operator=(const SmplAssign&);
	SmplAssign();
	void Edit(Input*pIn, Output*pOut);
	void setLHS(const string &L);
	void setRHS(double R);
	bool Within(Point) const;
	virtual void Draw(Output* pOut) const;
	void Move();
	void SmplAssign::Delete();
};

#endif