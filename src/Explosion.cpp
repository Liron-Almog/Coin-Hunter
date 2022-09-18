#include "Explosion.h"
#include "GameTexture.h"
#include "Const.h"

//-------------------Constructor---------------------
Explosion::Explosion()
{
	m_sprite.setTexture(*GameTexture::instance().getAnimationTexture(EXPLOSION));
	m_sprite.setOrigin(35.f, 35.5f);
}

//The function updates animation and kills self after it's finished all animation

//-------------------updateAni---------------------
void Explosion::updateAni(const float& deltaTime) {

	auto CurrentImage = m_explosionAnimation.getCurrentImage();

	m_explosionAnimation.update(m_AnimationRow, deltaTime);
	if (CurrentImage.x == m_explosionAnimation.getImageCount().x - 1)
		m_AnimationRow++;//passes to next row

	if (m_AnimationRow == m_explosionAnimation.getImageCount().y - 1 &&
		CurrentImage.x == m_explosionAnimation.getImageCount().x - 1)
		setDisposed();//kill Animation
}
//-----------draw------------------------
void Explosion::draw(sf::RenderWindow& window) {

	m_sprite.setTextureRect(*m_explosionAnimation.get_uvRect());
	window.draw(m_sprite);

}

