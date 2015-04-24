#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point &P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}

bool Input::ButtonState()
{
	return buttonstate();
}

string Input::GetString(Output *pO) const 
{
	string Str;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Str;
		if(Key == 8 )	//BackSpace is pressed
			Str.resize(Str.size() -1 );			
		else
			Str += Key;
		pO->PrintMessage(Str);
	}
	
}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D
	double D;
	
	pO->PrintMessage("Please enter a value");
	

	//Read a double value from the user
	
	return D;
}


ActionType Input::GetUserAction() const
{	
	//This function reads the position where the user clicks to determine the desired action

	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.TlBrWdth)
		{	//Check whick Menu item was clicked
			if( x >= 0 && x < UI.MnItWdth  )
				return ADD_SMPL_ASSIGN;
			if( x >= UI.MnItWdth && x < 2* UI.MnItWdth  )		
				return ADD_CONDITION;
			if( x >= UI.MnItWdth && x < 3* UI.MnItWdth  )		
				return EXIT;

			return DSN_TOOL;	//a click on empty part of the tool bar
		
		}
		
		//[2] User clicks on the drawing area
		if ( y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}

Input::~Input()
{
}