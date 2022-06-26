#pragma once
#include "Const.h"
class InfoLevel
{
public:

	void draw(sf::RenderWindow& window ,const float&, const unsigned& ,
										const unsigned& , const unsigned& );
	InfoLevel();
	~InfoLevel() = default;
	void resetTextInfo();
	void loadSprite();
	void setTextInformation();
	void setInformationPos(const float &);
	void resetPosition();

private:

	sf::Sprite m_lives[MAXIMUM_LIVES],
				m_bullets[MAX_BULLETS],
				m_star[MAXIMUM_STAR];
	sf::Text m_infoText[NUBER_OF_INFO];
	
};

