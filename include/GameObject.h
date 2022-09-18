#pragma once
#include "Const.h"

class GameObject 
{
public:

	GameObject();
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window) =0 ;
	void setDisposed() ;
	void setTilePosition(const sf::Vector2f pos);
	bool isDisposed() const;
	const sf::Sprite& getSprite() const;

protected:

	bool m_isDisposed = false;
	sf::Sprite m_sprite;
	
private:

};

