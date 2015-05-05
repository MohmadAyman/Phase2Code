#pragma once
#include "C:\Users\MohmadAyman\Documents\CMP103 Project S2015 - ALL Docs - student\Project Framework\Actions\Action.h"
class Copy :
	public Action
{
public:
	Copy(ApplicationManager*);
	~Copy();
	void ReadActionParameters();
	void Execute();
};

