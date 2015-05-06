#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

/// Class Edit body is still empty //////////////////////////////
class Edit :
	public Action
{
	Point Position;
public:
	Edit(ApplicationManager*);
	~Edit();
	void ReadActionParameters();
	void Execute();
	virtual void ExecuteCopy(const Statement &);

};

