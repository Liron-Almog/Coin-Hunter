#pragma once
#include "StaticObject.h"
class StartFlag : public StaticObject
{
public:
	StartFlag();
	~StartFlag() = default;

private:
	static bool m_registerit;
};

