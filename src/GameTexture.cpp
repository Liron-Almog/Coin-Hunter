#include "const.h"
#include "GameTexture.h"
//----------getTexturOfPlayers------------
const sf::Texture* GameTexture::getTexturOfPlayers(const int & num) const {
	return &m_playerTexture[num];
}

//---------loadPlayers--------------
void GameTexture::loadPlayers() {

	m_playerTexture[WALL].loadFromFile("Wall.png");
	m_playerTexture[FIRE].loadFromFile("Fire.jpg");
	m_playerTexture[STAR].loadFromFile("Star.png");
	m_playerTexture[DOOR].loadFromFile("Door.png");
	m_playerTexture[ENEMY].loadFromFile("Enemy.png");
	m_playerTexture[START_FLAG].loadFromFile("Start-flag.png");
	m_playerTexture[BULLET].loadFromFile("Bullet.png");
	m_playerTexture[TREE].loadFromFile("tree.png");
	m_playerTexture[PLAYER].loadFromFile("Player.png");
	m_playerTexture[BOMB].loadFromFile("Bomb.png");
	m_playerTexture[HEART].loadFromFile("Heart.png");
	
}
//---------loadTransitionScreen---------
void GameTexture::loadTransitionScreen() {

	m_transitionScreen[NEXT_LEVEL].loadFromFile("NextLevel.jpg");
	m_transitionScreen[GAME_OVER_BG].loadFromFile("GameOver.jpg");
	m_transitionScreen[TIME_IS_OVER].loadFromFile("TimeIsOver.png");
	m_transitionScreen[START].loadFromFile("Start.png");
	m_transitionScreen[QUIT].loadFromFile("Quit.png");
}
//----------Constructor----------------
GameTexture::GameTexture()
{
	loadPlayers();
	loadTransitionScreen();
	loadBackground();
	loadInfoTexture();
	m_animationTexture[EXPLOSION].loadFromFile("Explosion.png");
}
//--------------loadBackground-----------------
void GameTexture::loadBackground() {

	m_background[GAME_BG].loadFromFile("Game.jpg");
	m_background[MENU_BG].loadFromFile("Menu.jpg");
	m_background[INFORMATION].loadFromFile("Information.png");
	
}
//--------------loadInfoTexture----------------
void GameTexture::loadInfoTexture() {

	m_InfoTexture[HEART_INFO].loadFromFile("Heart.png");
	m_InfoTexture[BULLET_INFO].loadFromFile("Bullet2.png");
	m_InfoTexture[STAR_INFO].loadFromFile("Star2.png");
}
//------------getAnimationTexture---------
const sf::Texture* GameTexture::getAnimationTexture(const int& num) const {
	return &m_animationTexture[num];
}
//------------------instance-----------------
GameTexture& GameTexture::instance() {
	static GameTexture inst;
	return inst;
}
//-----------------getBG-----------------
const sf::Texture* GameTexture::getBG(const int & num) const {

	return &m_background[num];
}
//-----------------getTransitionScreen-----------------
const sf::Texture* GameTexture::getTransitionScreen(const int& num) const {
	
	return &m_transitionScreen[num];
}
////--------------------getInformaionTexture---------------------
const sf::Texture* GameTexture::getInformaionTexture(const int& num) const {

	return &m_InfoTexture[num];
}
