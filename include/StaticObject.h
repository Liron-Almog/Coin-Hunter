#pragma once
#include "GameObject.h"

class StaticObject : public GameObject
{

	
public:

	virtual void updateAni(const float&) {}
	void draw(sf::RenderWindow& window) ;

private:


};