#pragma once
#include "Actions/Action.h"
class Move :
	public Action
{
	Point Position;	//Position where the user clicks to add the stat.
public:
	Move(ApplicationManager*);
	~Move();
	void Move::ReadActionParameters();
	void Move::Execute();
	virtual void Move::ExecuteCopy(const Statement &);

};
//test
///testtt
