#include "Star.h"

//-----------Constructor-------------
Star::Star()
{
	m_sprite.setTexture(*GameTexture::instance().getTexturOfPlayers(STAR));
}

//The function updates the animation 
//-----------updateAni-------------
void Star::updateAni(const float& deltaTime) {
	m_gobletAnimation.update(0, deltaTime);
}
//--------------draw---------------
void Star::draw(sf::RenderWindow& window) {
	
	m_sprite.setTextureRect(*m_gobletAnimation.get_uvRect());
	window.draw(m_sprite);

}