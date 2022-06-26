#pragma once
#include "Const.h"
class Command {
	
public:

	Command();
	virtual ~Command() = default;
	virtual bool execute(sf::RenderWindow& window) = 0;
	void setText(const string&, const sf::Vector2i&);
	void drawTransitionScreen(sf::RenderWindow&);
	const sf::Text & getText() const;

protected:
	sf::Sprite m_transitionScreen;

private:
	sf::Text m_text;
	
};

