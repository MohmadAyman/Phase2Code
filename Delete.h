#pragma once
#include "C:\Users\MohmadAyman\Documents\CMP103 Project S2015 - ALL Docs - student\Project Framework\Actions\Action.h"
#include <sstream>
class Delete :
	public Action
{
	Point Position;
public:
	Delete(ApplicationManager*);
	~Delete();
	void ReadActionParameters();
	virtual void ExecuteCopy(const Statement &);

	void Execute();
};

