#pragma once
#include "StaticObject.h"
#include "Const.h"
#include "Factory.h"
class Door : public StaticObject
{
public:
	Door();
	~Door() = default;

private:
	static bool m_registerit;
};
