#pragma once

#include "StaticObject.h"
#include "Factory.h"
class Tree : public StaticObject
{
public:
	Tree();
	~Tree() = default;

private:
	static bool m_registerit;
};

