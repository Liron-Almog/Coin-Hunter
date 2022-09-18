#pragma once
#include "StaticObject.h"

class StaticBullet : public StaticObject
{
public:
	StaticBullet();
	~StaticBullet() =default;

private:
	static bool m_registerit;
};

