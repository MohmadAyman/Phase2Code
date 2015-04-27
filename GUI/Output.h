#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();	
	void DrawStart(Point P,bool selected);
	void DrawEnd(Point P,bool selected);
	window* CreateWind(int, int, int , int);
	void ClearToolBar();
	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar();//Tool bar of the simulation mode

	void CreateStatusBar();

	Input* CreateInput(); //creates a pointer to the Input object	
	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea();	//Clears the drawing area

	// -- Statements Drawing Functions
	void DrawAssign(Point Left, int width, int height, string Text, bool Selected=false);
	void DrawCondition(Point Left, int width , int height ,string Text ,bool Selected=false);
	//TODO: Add similar functions for drawing all other statements.
	//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
	//		Decide the parameters that should be passed to each of them

		
	void PrintMessage(string msg);	//Prints a message on Status bar
	
	~Output();
};

#endif