#include "Enemy.h"

//-------------Constructor-----------------
Enemy::Enemy()
{
	m_sprite.setTexture(*GameTexture::instance().getTexturOfPlayers(ENEMY));
}
//---------------move------------------------
void Enemy::move(const float & deltaTime) {
	
	m_sprite.move(sf::Vector2f(m_direction.x * ENEMY_SPEED * deltaTime,
									m_direction.y * ENEMY_SPEED * deltaTime));
	m_enemyAnimation.update(m_enemyAnimation.getRowOfStandatAni(m_direction), deltaTime);

}
//The function chenges the direction of enemy to anther 
// direction ,so that last direction not same like new direction 
//-------------changeDirection---------------
void Enemy::changeDirection() {

	int lastDir = m_dir;

	m_sprite.move(-m_direction.x*3 , -m_direction.y*3); //move one step back
	m_dir = rand();			   // choose a random direction
	m_dir %= NUM_OF_DIRECTIONS;

	m_direction = getDirection(m_dir);
	if (m_dir == lastDir) {//checks if it's not the same direction like last 
		m_dir++;
		m_dir %= NUM_OF_DIRECTIONS;
		m_direction = getDirection(m_dir);
	}
		
}
//The function gets nubmer between 0-4 
// and returns direction
//--------getDirection---------
sf::Vector2f Enemy::getDirection(const int &newDir) const { 

	switch (newDir) {

	case 0: return LEFT;
	case 1: return RIGHT;
	case 2: return  UP;
	case 3: return DOWN;

	}

}
//---------------draw-------------------
void Enemy::draw(sf::RenderWindow& window) {

	m_sprite.setTextureRect(*m_enemyAnimation.get_uvRect());
	window.draw(m_sprite);

}