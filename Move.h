#pragma once
#include "Action.h"
class Move :
	public Action
{
	Point Position;	//Position where the user clicks to add the stat.
public:
	Move(ApplicationManager*);
	~Move();
	void Move::ReadActionParameters();
	void Move::Execute();
};
//test
///testtt
