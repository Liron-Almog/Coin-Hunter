#pragma once
#pragma once
#include "StaticObject.h"

class Heart : public StaticObject
{
public:
	Heart();
	~Heart() = default;

private:
	static bool m_registerit;
};

