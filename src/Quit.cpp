#include "Quit.h"
#include "GameTexture.h"
//The virtual function executes the quit button in the menu 
//----------execute-------------
bool Quit::execute(sf::RenderWindow& window) {

	drawTransitionScreen(window);
	return false;
}
//----------Constructor-------------
Quit::Quit() {
	m_transitionScreen.setTexture(*GameTexture::instance().getTransitionScreen(QUIT));
	
} 
