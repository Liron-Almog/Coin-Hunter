#pragma once
#include "Command.h"
#include "GameTexture.h"
#include "Controller.h"
#include "Const.h"
class Start : public Command
{

public:

	 bool execute(sf::RenderWindow& window) ;
	Start();
	virtual ~Start() = default;

private:
	
};

