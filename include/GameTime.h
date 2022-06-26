#pragma once
#include "Const.h"
class GameTime
{
public:

	GameTime();
	~GameTime() = default;

	int getTime() const;
	void resetPosition();
	void setTimePosition(float x);
	void startTime(const int &);
	void updateTime();
	void drawTime(sf::RenderWindow& window) ;

private:

	sf::Text m_infoTime
			,m_textTime;
	int m_totalTime;
	sf::Clock m_gameTime;
	sf::Sprite m_TimeIsOver;
};

