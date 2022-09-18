#pragma once
#include "Command.h"
#include "Const.h"

class Menu {

public:
	void draw(sf::RenderWindow&) const;
	void add(string name, unique_ptr<Command> c, sf::Vector2i pos);
	~Menu() = default;
	Menu(string name, const sf::Texture&,  sf::Vector2i);
	void changeCursorIfOnButton(const sf::Vector2i pos, sf::RenderWindow& window) const;
	int optionFromUser(sf::Event event, sf::RenderWindow& window) const;
	void activate(sf::RenderWindow& window);
	bool performAction(const int& n, sf::RenderWindow& window) const;
	void drawOption(sf::RenderWindow& window) const;
	void moveBG(const int&, const int&);
private:
	
	typedef pair<string, unique_ptr<Command>> option;
	vector<option> m_options;
	sf::Text m_textTitle;
	sf::Sprite m_BG;
};
