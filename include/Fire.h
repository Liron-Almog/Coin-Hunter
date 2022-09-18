#pragma once
#include "StaticObject.h"
#include "Const.h"
#include "Animation.h"
#include "GameTexture.h"
#include "Factory.h"
class Fire : public StaticObject
{
public:

	Fire();
	~Fire() = default;
	void draw(sf::RenderWindow& window);
	void updateAni(const float&);

private:

	static bool m_registerit;
	unsigned m_AnimationRow = 0;
	Animation m_fireAnimation = Animation(*GameTexture::instance().getTexturOfPlayers(FIRE), 
									sf::Vector2u(COLS_NUM_ANI_FIRE, ROWS_NUM_ANI_FIRE), TIME_BET_ANI_FIRE);
};

