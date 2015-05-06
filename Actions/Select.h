#pragma once
#include "Action.h"

class Select :
	public Action
{
	Point Position;	//Position where the user clicks to add the stat.
public:
	Select(ApplicationManager *);
	~Select();
	void ReadActionParameters();
	void Execute();
	virtual void ExecuteCopy(const Statement &);

};

