#pragma once
#include "Actions\Action.h"

class MultiSelect :
	public Action
{
	Point Position;
public:
	MultiSelect(ApplicationManager *	);
	~MultiSelect();
	void ReadActionParameters();
	void Execute();
	void ExecuteCopy(const Statement &);

};