#include "Bullet.h"
//---------------Constructor-----------------
Bullet::Bullet()
{
	m_sprite.setTexture(*GameTexture::instance().getTexturOfPlayers(BULLET));
	
}
//----------------move-------------------
void Bullet::move(const float& deltaTime) {
	
	m_sprite.move(m_direction.x * deltaTime * BULLET_SPEED *2, m_direction.y * deltaTime * BULLET_SPEED*2);
}
//-------------------draw--------------
void Bullet::draw(sf::RenderWindow& window) {

	window.draw(m_sprite);
}
//---------------setDireation---------------
void Bullet::setDireation(const sf::Vector2f& dir) {

	m_direction = sf::Vector2f(dir.x, dir.y);
}