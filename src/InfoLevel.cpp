#include "infoLevel.h"
#include "GameFont.h"
#include "GameTexture.h"
//---------setTextInformation-------
void InfoLevel::setTextInformation() {

	for (size_t i = 0; i < NUBER_OF_INFO; i++)
	{
		m_infoText[i].setFont(GameFont::instance().getFont(FONTINFO_FONT));
		m_infoText[i].setColor(sf::Color::White);
		m_infoText[i].setCharacterSize(35);
	}
	m_infoText[LIVES].setString("Lives:");
	m_infoText[STARS].setString("Stars:");
	m_infoText[BULLETS].setString("Bullets:");
	m_infoText[STAGE].setString("Stage:");
}
//The function resets the position of informaion 
//---------resetPosition-------
void InfoLevel::resetPosition() {

	resetTextInfo();
	//lives
	for (size_t i = 0; i < MAXIMUM_LIVES; i++) 
		m_lives[i].setPosition(175 + i * 45, 70);
	//stars
	for (size_t i = 0; i < MAXIMUM_STAR; i++) 
		m_star[i].setPosition(475 + i * 45, 70);
	//bullets
	for (size_t i = 0; i < MAXIMUM_BULLETS; i++) 
		m_bullets[i].setPosition(1353 + i * 23, 70);
	
}
//-------------resetTextInfo-------------
void InfoLevel::resetTextInfo() {

	m_infoText[LIVES].setPosition(LIVES_TEXT_POS);
	m_infoText[STARS].setPosition(STARS_TEXT_POS);
	m_infoText[BULLETS].setPosition(BULLETS_TEXT_POS);
	m_infoText[STAGE].setPosition(STAGE_TEXT_POS);
	m_infoText[TEXT_OF_STAGE].setPosition(STAGE_TEXT_POS.x + 100, STAGE_TEXT_POS.y);
}
//----------------consrctor----------------
InfoLevel::InfoLevel()
{
	setTextInformation();
	loadSprite();
}
//----------------loadSprite----------------
void InfoLevel::loadSprite() {

	for (size_t i = 0; i < MAXIMUM_LIVES; i++)
		m_lives[i].setTexture(*GameTexture::instance().getInformaionTexture(HEART_INFO));
		
	for (size_t i = 0; i < MAXIMUM_STAR; i++)
		m_star[i].setTexture(*GameTexture::instance().getInformaionTexture(STAR_INFO));
		
	for (size_t i = 0; i < MAXIMUM_BULLETS; i++)
		m_bullets[i].setTexture(*GameTexture::instance().getInformaionTexture(BULLET_INFO));
}
//-------------draw------------------------
void InfoLevel::draw(sf::RenderWindow& window, const float & bullets, const unsigned &stage,
							const unsigned &lives, const unsigned &stars) {

	m_infoText[TEXT_OF_STAGE].setString(std::to_string(stage));

	for (size_t i = 0; i < lives; i++)	
		window.draw(m_lives[i]);
	
	for (size_t i = 0; i < NUBER_OF_INFO; i++)
		window.draw(m_infoText[i]);

	for (size_t i = 0; i < stars; i++)
		window.draw(m_star[i]);

	for (size_t i = 0; i < bullets; i++)
		window.draw(m_bullets[i]);
}
//The function sets the information position
//------------setInformationPos-------------
void InfoLevel::setInformationPos(const float& x) {

	for (size_t i = 0; i < MAXIMUM_LIVES; i++)
		m_lives[i].setPosition(175 + i * 45 +x, LIVES_TEXT_POS.y);
	
	m_infoText[LIVES].setPosition(85 + x, LIVES_TEXT_POS.y);
	m_infoText[STARS].setPosition(355 + x, STARS_TEXT_POS.y);
	m_infoText[BULLETS].setPosition(1220 + x, BULLETS_TEXT_POS.y);
	m_infoText[STAGE].setPosition(1058 + x, STAGE_TEXT_POS.y);
	m_infoText[TEXT_OF_STAGE].setPosition(1158 + x, STAGE_TEXT_POS.y);

	for (size_t i = 0; i < MAXIMUM_STAR; i++)
		m_star[i].setPosition(475 + i * 45 +x, STARS_TEXT_POS.y);
	
	for (size_t i = 0; i < MAXIMUM_BULLETS; i++)
		m_bullets[i].setPosition(1353 + i * 23 +x, BULLETS_TEXT_POS.y);

}

