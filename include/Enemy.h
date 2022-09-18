#pragma once
#include "UnControllerObj.h"
#include "Const.h"
#include "Animation.h"
#include "Factory.h"
#include "GameTexture.h"
class Enemy : public UnControllerObj
{
public:

	Enemy();
	~Enemy()= default;
	void move(const float&) override;
	void draw(sf::RenderWindow&) override;
	void changeDirection();
	sf::Vector2f getDirection(const int& newDir) const;
	
private:

	int m_dir = 0;
	static bool m_registerit;
	sf::Vector2f m_direction = sf::Vector2f(1, 0);
	Animation m_enemyAnimation = Animation(*GameTexture::instance().
			getTexturOfPlayers(ENEMY), sf::Vector2u(COLS_NUM_ANI_ENEMY, 
								ROWS_NUM_ANI_ENEMY), TIME_BET_ANI_ENEMY);
};
