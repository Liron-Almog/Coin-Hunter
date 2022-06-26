#include "Start.h"
#include "GameSound.h"
//The virtual function executes the start button in the menu 
//-----------execute-------------
bool Start::execute(sf::RenderWindow& window) {

	GameSound::instance().pauseMenuMusic(MENU_MUSIC);
	Controller game;

	drawTransitionScreen(window);
	GameSound::instance().playMenuMusic(GAME_MUSIC);
	game.run(window);
	GameSound::instance().pauseMenuMusic(GAME_MUSIC);
	GameSound::instance().playMenuMusic(MENU_MUSIC);
	//returns background to starting point
	auto view = sf::View(sf::FloatRect(0, 0, SCREEN_W, SCREEN_H));
	window.setView(view);
	return true;
}
//-----------constructor-------------
Start::Start() {
	m_transitionScreen.setTexture(*GameTexture::instance().getTransitionScreen(START));
}
