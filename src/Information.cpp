#include "Information.h"
#include "Command.h"
#include "Menu.h"
#include "GameTexture.h"
#include "Back.h"
#include "Const.h"

//The virtual function executes the information button in the menu 
 bool Information::execute(sf::RenderWindow& window) {

	 Menu informationMenu("", *GameTexture::instance().getBG(INFORMATION), sf::Vector2i(0, 0));
	 informationMenu.moveBG(100, 0);
	 informationMenu.add("Back", std::make_unique<Back>(),sf::Vector2i(SCREEN_W /1.15, SCREEN_H / 1.2));
	 informationMenu.draw(window);
	 informationMenu.activate(window);

	 return true;
}

 