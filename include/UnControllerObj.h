#pragma once

#include "MovingObj.h"
class UnControllerObj :public MovingObj
{
public:

	virtual void move(const float&) = 0;
	UnControllerObj () = default;
	~UnControllerObj ()= default;

private:

};

