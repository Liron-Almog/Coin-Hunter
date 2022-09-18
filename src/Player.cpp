#include "Player.h"
#include "GameFont.h"

//---------moveStepBack-------------
void Player::moveStepBack() {
	m_sprite.move(-m_lastDireation);
}

//The function moves the player and updates animation
//---------move-------------
void Player::move(const sf::Vector2f & direction, const float& deltaTime){

	m_lastDireation = sf::Vector2f(direction.x  * PLAYER_SPEED * deltaTime, direction.y  * PLAYER_SPEED * deltaTime);
	m_sprite.move(m_lastDireation);
	m_playerAnimation.update(m_playerAnimation.getRowOfStandatAni(direction), deltaTime);
}

//---------constructor----------
Player::Player()
{
	m_sprite.setTexture(*GameTexture::instance().getTexturOfPlayers(PLAYER));
	m_sprite.scale(1.1, 1.1);
}

//------------draw----------------
 void Player::draw(sf::RenderWindow& window)  {

	 m_sprite.setTextureRect(*m_playerAnimation.get_uvRect());
	 window.draw(m_sprite);
}
 //------------getLastDirection----------------
 const sf::Vector2f& Player::getLastDirection() const {
	 return m_lastDireation;
 }

 //------------setDirection------------
void Player::setDirection(const sf::Vector2f& dir) {
	m_lastDireation = dir;
 }

//------------decBullet------------
void Player::decBullet() {
	m_bullets--; 
}

//------------decStars-----------------
void Player::decStars() {

	if(m_starts > 0)
		m_starts--;
}
//----------incBullet----------
void Player::incBullet() {

	if(MAXIMUM_BULLETS > m_bullets)
		m_bullets++;
}

//--------getBullets-----------
const float & Player::getBullets() const {
	return m_bullets;
}

//---------getStars-------------
const unsigned & Player::getStars() const {
	return m_starts;
}