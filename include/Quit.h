#pragma once
#include "Command.h"
class Quit : public Command
{
public:
	virtual bool execute(sf::RenderWindow&);
	Quit();
	virtual ~Quit() = default;
private:
	
};

