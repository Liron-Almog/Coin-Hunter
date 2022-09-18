#pragma once
#include "StaticObject.h"
#include "Factory.h"
#include "Animation.h"
#include "GameTexture.h"
class Star : public StaticObject
{
public:

	Star();
	~Star() = default;
	void draw(sf::RenderWindow& window);
	void updateAni(const float&) override;

private:
	static bool m_registerit;
	Animation m_gobletAnimation = Animation(*GameTexture::instance()
					.getTexturOfPlayers(STAR), sf::Vector2u(COLS_NUM_ANI_STAR, ROWS_NUM_ANI_STAR), TIME_BET_ANI_STAR);
};
