#pragma once
#include "Command.h"
class Back :public Command
{
public:
	virtual bool execute(sf::RenderWindow&);
	Back() = default;
	virtual ~Back() = default;
	
private:

};

