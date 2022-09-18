#include "Menu.h"
#include "FactoryObj.h"
#include "Start.h"
#include "Information.h"
#include "GameTexture.h"
#include "GameSound.h"
#include "Quit.h"

int main()
{
	
	try {
		sf::RenderWindow window(sf::VideoMode(1600, 800, 32), "Coin Hunter", sf::Style::Close);
		Menu menu("Coin Hunter", *GameTexture::instance().getBG(MENU_BG), sf::Vector2i(400, 55));

		//adds buttons to menu
		menu.add("Quit", std::make_unique<Quit>(), sf::Vector2i(SCREEN_W / 2 - 65, SCREEN_H + -85 - 240));
		menu.add("Information", std::make_unique<Information>(), sf::Vector2i(SCREEN_W / 2 - 130, SCREEN_H + -170 - 240));
		menu.add("Start", std::make_unique<Start>(), sf::Vector2i(SCREEN_W / 2 - 72, SCREEN_H + -255 - 240));
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

