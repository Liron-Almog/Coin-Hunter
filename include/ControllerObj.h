#pragma once
#include "MovingObj.h"

class ControllerObj :public MovingObj
{
public:
	void incLives();
	ControllerObj() = default;
	~ControllerObj() = default;
	const unsigned getLives() const;
	virtual void moveStepBack() = 0;
	virtual void move(const sf::Vector2f& , const float&) = 0;
	void setLives(const unsigned& num);
	void decLive();

protected:
	unsigned m_lives = MAXIMUM_LIVES;
private:

};
