#pragma once
#include "Bullet.h"
#include "UnControllerObj.h"
#include "Const.h"
#include "Animation.h"
#include "GameTexture.h"
class Bullet : public UnControllerObj
{
public:

	void setDireation(const sf::Vector2f& dir);
	Bullet();
	~Bullet() = default;
	void move(const float&) override;
	void draw(sf::RenderWindow& window) ;

private:
	static bool m_registerit;
	sf::Vector2f m_direction ;
	
};

