#include "Statement.h"

Statement::Statement()	
{ 
	Text = "";
	Selected = false;		
}
Statement::Statement(const Statement & s)
{
	this->Selected = s.Selected;
	this->Text = s.Text;
}


void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

