#include "GameFont.h"
#include "Const.h"
//-------------------instance--------------------
GameFont& GameFont::instance() {
	static GameFont inst;
	return inst;
}
//----------------getFont-----------------------
const sf::Font& GameFont::getFont(const int & num) const {

	return m_fontGame[num];
}
//----------------constructor-------------------
GameFont::GameFont() {

	m_fontGame[CANDY_FONT].loadFromFile("JungleAdventurer.ttf");
	m_fontGame[ASDONUTS_FONT].loadFromFile("Asdonuts.ttf");
	m_fontGame[FONTINFO_FONT].loadFromFile("fontinfo.otf");
	m_fontGame[DIGITAL_FONT].loadFromFile("digital-7.ttf");
}

