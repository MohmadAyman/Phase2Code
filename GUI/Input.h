#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(Point &P) const;//Get coordinate where user clicks
	
	double GetValue(Output* pO) const;	// Reads a double value from the user 

	string GetString(Output* pO) const ; //Returns a string entered by the user

	ActionType GetUserAction() const; //Read the user click and map it to an action
	bool ButtonState();

	~Input();
};

#endif