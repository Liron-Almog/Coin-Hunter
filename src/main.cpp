#include "Menu.h"
#include "FactoryObj.h"
#include "Start.h"
#include "Information.h"
#include "GameTexture.h"
#include "GameSound.h"
#include "Quit.h"
#include <time.h>
int main(){
	try {
		srand(time(NULL));
		sf::RenderWindow window(sf::VideoMode(1600, 800, 32), "Coin Hunter", sf::Style::Close);
		Menu menu("Coin Hunter", *GameTexture::instance().getBG(MENU_BG), TITLE_POS);
	
		//adds buttons to menu
		menu.add("Quit", std::make_unique<Quit>(), QUIT_POS);
		menu.add("Information", std::make_unique<Information>(), INFO_POS);
		menu.add("Start", std::make_unique<Start>(), START_POS);
		GameSound::instance().playMenuMusic(MENU_MUSIC);

		menu.draw(window);
		menu.activate(window);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return EXIT_FAILURE;
	}

	catch (...) {
		std::cerr << "Unknown exception\n";
		return EXIT_FAILURE;
	}
}

