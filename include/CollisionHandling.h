#pragma once

#include "Const.h"

class CollisionHandling
{
public:

	
	CollisionHandling();
	~CollisionHandling() = default;
	void processCollision(GameObject& object1, GameObject& object2);
	HitFunctionPtr lookUp(const std::type_index& class1, const std::type_index& class2);
	
private:
	HitMap m_collisionMap;
};

