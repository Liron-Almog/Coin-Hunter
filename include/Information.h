#pragma once
#include "Command.h"
class Information : public Command
{
public:
	virtual bool execute(sf::RenderWindow& window);
	Information() = default;
	virtual ~Information() =default;
private:
};
