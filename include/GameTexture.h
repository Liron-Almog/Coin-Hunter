#pragma once
#include "Const.h"

class GameTexture
{
public:


	~GameTexture() = default;
	static GameTexture& instance();

	//------------------get function-------------------
	const sf::Texture* getTransitionScreen(const int&) const;
	const sf::Texture* getTexturOfPlayers(const int&) const;
	const sf::Texture* getInformaionTexture(const int&) const;
	const sf::Texture* getAnimationTexture(const int&) const;
	const sf::Texture* getBG(const int&) const;

private:

	void loadBackground();
	void loadInfoTexture();
	void loadPlayers();
	void loadTransitionScreen();
	GameTexture();
	GameTexture(const GameTexture&) = default;
	GameTexture& operator=(const GameTexture&) = default;
	sf::Texture m_background[BG_NUMBER];
	sf::Texture m_transitionScreen[TRANSITION_SCREENS];
	sf::Texture m_playerTexture[NUMBER_OF_OBJECT];
	sf::Texture m_InfoTexture[NUMBER_OF_ICON_INFO];
	sf::Texture m_animationTexture[NUMBER_OF_ANIMATION];
};
