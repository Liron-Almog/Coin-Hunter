#include "GameObject.h"

GameObject::GameObject()
{
	
}
//-----------setPlayerPosition------------
void GameObject::setTilePosition(const sf::Vector2f pos) {
	m_sprite.setPosition(pos.x, pos.y);
}
//---------------isDisposed--------------
bool GameObject::isDisposed() const
{
	return m_isDisposed;
}
//---------------isDisposed--------------
void GameObject::setDisposed() 
{
	m_isDisposed = true;
}
//------------getSprite------------
const sf::Sprite & GameObject::getSprite() const{
	return m_sprite;
}
