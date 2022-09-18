#pragma once
#include "StaticObject.h"
#include "Factory.h"
class Wall : public StaticObject
{
public:
	Wall();
	~Wall() = default;

private:
	static bool m_registerit;
};

