#pragma once
#include "Fire.h"
#include "GameTexture.h"
#include "Const.h"

//---------Constractor---------------
Fire::Fire()
{
	m_sprite.setTexture(*GameTexture::instance().getTexturOfPlayers(FIRE));
	m_sprite.setScale(0.3, 0.3);
}
//---------updateAni---------------
void Fire::updateAni(const float& deltaTime) {

	m_fireAnimation.update(m_AnimationRow, deltaTime);
	//if last column,so goes to next row modulu number of rows
	if (m_fireAnimation.getCurrentImage().x == m_fireAnimation.getImageCount().x - 1)
		m_fireAnimation.setCurrentRow((m_fireAnimation.getCurrentImage().y +1) % m_fireAnimation.getImageCount().y);

}
//---------draw---------------
void Fire::draw(sf::RenderWindow& window) {

	m_sprite.setTextureRect(*m_fireAnimation.get_uvRect());
	window.draw(m_sprite);

}

