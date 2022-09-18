#pragma once

#include "Factory.h"
#include "Animation.h"
#include "ControllerObj.h"
#include "GameTexture.h"
#include "Const.h"
class Player: public ControllerObj
{
public:

	Player();
	~Player() = default;
	void decBullet();
	void decStars();
	void incBullet();
    void move(const sf::Vector2f&, const float&);
	void moveStepBack();
	void draw(sf::RenderWindow& window) ;
	const sf::Vector2f& getLastDirection() const;
	void setDirection(const sf::Vector2f&);
	const float & getBullets() const ;
	const unsigned & getStars() const ;
	
private:

	unsigned m_starts = MAXIMUM_STAR;
	float m_bullets = MAXIMUM_BULLETS;
	sf::Vector2f m_lastDireation =DOWN;
	static bool m_registerit;
	Animation m_playerAnimation = Animation(*GameTexture::instance().getTexturOfPlayers(PLAYER)
		, sf::Vector2u(COLS_NUM_ANI_PLAYER , ROWS_NUM_ANI_PLAYER), TIME_BET_ANI_PLAYER);
};

