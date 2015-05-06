#pragma once
#include "C:\Users\MohmadAyman\Documents\CMP103 Project S2015 - ALL Docs - student\Project Framework\Actions\Action.h"
class Cut :
	public Action
{
	Point Position;
public:
	Cut(ApplicationManager*);
	~Cut();
	void ReadActionParameters();
	void Execute();
    void ExecuteCopy(const Statement &);
};

