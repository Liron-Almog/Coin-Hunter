#pragma once
#include "StaticObject.h"
#include "Animation.h"
#include "GameTexture.h"
class Explosion :public StaticObject
{
public:
	Explosion();
	~Explosion() = default;
	void draw(sf::RenderWindow& window);
	void updateAni(const float&);

private:
	static bool m_registerit;
	unsigned m_AnimationRow = 0;
	Animation m_explosionAnimation = Animation(*GameTexture::instance()
				.getAnimationTexture(EXPLOSION), 
			sf::Vector2u(COLS_NUM_ANI_EXPLOSION, ROWS_NUM_ANI_EXPLOSION), TIME_BET_ANI_EXPLSION);
};
