#include "Map.h"
#include "GameObject.h"
#include "Factory.h"
#include <ctype.h>
#include "GameTexture.h"
#include "ControllerObj.h"
#include "CollisionHandling.h"
#include "Wall.h"
#include "Player.h"
#include "Bullet.h"
#include "GameSound.h"
#include <iostream>     
#include <fstream>
#include "Door.h"
#include "Enemy.h"
#include "Heart.h"

//The function checks collision between all the players 
// and does the appropriate operation as result from collisions.
//---------checkCollistion-----------
void Map::checkCollistion(sf::RenderWindow& window, const float& deltaTime) {

	unControlledObjWithStatic();
	unControlledObjWithThemSelves();
	controllerdObjWithOthers();
	specialEventsCuzColistion(window, deltaTime);

}
//------------specialEventsCuzColistion--------------
void Map::specialEventsCuzColistion(sf::RenderWindow& window, const float& deltaTime) {

	specialEventsWithUnControllerObj(window, deltaTime);
	specialEventsWithStaticObj();

	if (m_player->isDisposed()){ 
		readMapOrGameOver();
		return;
	}
	deleteDisposedObj();
}
//The function checks special event as result from collision
// with StaicObj.
//---specialEventsWithStaticObj----------
void Map::specialEventsWithStaticObj() {

	for (size_t i = 0; i < m_staticObj.size(); i++) {//checks if player finished the stage
		if (m_staticObj[i]->isDisposed() && typeid(*m_staticObj[i]) == typeid(Door))
			m_stage++;

		if (m_staticObj[i]->isDisposed() && typeid(*m_staticObj[i]) == typeid(Heart))
			m_lives = m_player->getLives();
	}
}
//The function reads the same step if a live player is left
// , turn on m_gameover
//------------------readMapOrGameOver------------------
void Map::readMapOrGameOver() {

	Player* player;
	player = static_cast<Player*>(m_player.get());

	m_lives--;
	if (player->getLives() > 0)
		readMap(false);

	else m_gameOver = true;
}
//The function checks special event as result from collision
// with UnControllerObj.
//-----------specialEventsWithUnControllerObj------------
void Map::specialEventsWithUnControllerObj(sf::RenderWindow& window, 
											const float& deltaTime) {

	for (size_t i = 0; i < m_unControllerObj.size(); i++) {

		//if dead terrorist creates explosion
		if (m_unControllerObj[i]->isDisposed() && typeid(*m_unControllerObj[i]) == typeid(Enemy)) {
			//Creates explosion
			m_staticObj.emplace_back(Factory<StaticObject>::create('e'));
			m_staticObj[m_staticObj.size() - 1] -> 
						setTilePosition((m_unControllerObj[i]->getSprite().getPosition()));
			GameSound::instance().soundEffects(EXPLOSION_SOUND);

			if (m_player->isDisposed()) {
				m_unControllerObj.erase(m_unControllerObj.begin() + i);
				for (size_t i = 0; i < SHOW_EXPOSION; i++)//draws to show explosion
					drawMap(window, deltaTime);
			}
		}
	}
}
//The function checks collision with UnControlledObj between themSelves
//------------UnControlledObjWithThemSelves-----------
void Map::unControlledObjWithThemSelves() {

	for (size_t i = 0; i < m_unControllerObj.size(); i++) 
		for (size_t j = 0; j < m_unControllerObj.size(); j++) 
			if (isColiistion(*m_unControllerObj[i], *m_unControllerObj[j]) && i != j)
				m_collisionHandling.processCollision(*m_unControllerObj[i],
													*m_unControllerObj[j]);
}
//The function deletes object that disposed
//--------------deleteDisposedObj-----------------
void Map::deleteDisposedObj() {

	for (size_t i = 0; i < m_unControllerObj.size(); i++)
		if (m_unControllerObj[i]->isDisposed())
			m_unControllerObj.erase(m_unControllerObj.begin() + i);

	for (size_t i = 0; i < m_staticObj.size(); i++) 
		if(m_staticObj[i]->isDisposed())
			m_staticObj.erase(m_staticObj.begin() + i);

}
//The function checks collision with ControlledObj between others
//--------------ControlledObjWithOthers-----------
void Map::controllerdObjWithOthers() {

	//Between static to hunter
	for (size_t i = 0; i < m_staticObj.size(); i++) {
		if (isColiistion(*m_player, *m_staticObj[i])) 
			m_collisionHandling.processCollision(*m_player, *m_staticObj[i]);
	}
	//Between m_unControllerObj to hunter
	for (size_t i = 0; i < m_unControllerObj.size(); i++) 
		if (isColiistion(*m_player, *m_unControllerObj[i]))
			m_collisionHandling.processCollision(*m_player, *m_unControllerObj[i]);
}
//The function checks colllision between 
// UncontrollerObg to others
//--------------unControlledObjWithStatic--------
void Map::unControlledObjWithStatic() {

	for (size_t i = 0; i < m_unControllerObj.size(); i++)
		for (size_t j = 0; j < m_staticObj.size() ; j++)
			if (isColiistion(*m_unControllerObj[i], *m_staticObj[j])){
				m_collisionHandling.processCollision(*m_unControllerObj[i], *m_staticObj[j]);
				}
}
//------------------isColiistion-------------------
bool Map::isColiistion(const GameObject & ob1 , const GameObject  & ob2) {
	
	if (ob1.getSprite().getGlobalBounds().intersects(ob2.getSprite().getGlobalBounds()))
		return true;
	return false;
}
//---------movePlayer-----------------
void Map::movePlayer(const sf::Vector2f& direction, const float& deltaTime) {

	m_player->move(direction, deltaTime);
}
//-----------readMap------------------
void Map::readMap(bool newLevel) {
	
	resetPositionOfinfo();
	m_gameStart = true;

	if (!newLevel) //if it's not new stage ,so returns the sign to same stage
		m_fileMaps.seekg(-((SIZE_MAP_R) * (SIZE_MAP_C + 2) +3), std::ios::cur);

 	m_fileMaps >> m_stage;
	//if we readed level from file that worth zero, then the game is over
	//or lives = 0 
	if (m_stage == GAME_OVER || m_lives == GAME_OVER) {
		m_gameOver = true;
		return;
	}

	m_gameTime.startTime(m_stage);
	clearArray();
	readMapFromFile();
}
//----------------isStartGame()-----------
bool Map::isGameStart() const {
	return m_gameStart;
}
//----------------isStartGame()-----------
void Map::setGameStart()  {
	m_gameStart = !m_gameStart;
}
//--------------readMapFromFile----------
void Map::readMapFromFile() {

	char tile;

	for (size_t row = 0; row < SIZE_MAP_R; row++) {
		tile = m_fileMaps.get();//eats the \n
		for (size_t col = 0; col < SIZE_MAP_C; col++)
		{
			tile = m_fileMaps.get();
			insertPlayer(tile, sf::Vector2f(col * WALL_SIZE, +row * WALL_SIZE));
		}
	}
	tile = m_fileMaps.get();//eats the \n
}
//-----------------clearArray---------
void Map::clearArray() {
	
	m_staticObj.clear();
	m_player.reset();
	m_unControllerObj.clear();
}
//The function checks if has to player bullet,
//then inserts new bullet to appropriate vector
//and sets the correct location according to player position.
//---------------shot--------------------
void Map::shot() {

	static int bulletsRegulator = 0; 
	Player* player;
	player = dynamic_cast<Player*>(m_player.get());

	if (bulletsRegulator % REGULATOR_6 == 0) {

		if (player->getBullets() > 0) {
			player->decBullet();
			auto playerPos = m_player->getSprite().getPosition();

			//creates bullet in the same position of player
			m_unControllerObj.emplace_back(Factory<UnControllerObj>::create('B'));
			m_unControllerObj[m_unControllerObj.size() - 1]->setTilePosition
			(sf::Vector2f(playerPos.x, playerPos.y + 35));

			GameSound::instance().soundEffects(SHOT_SOUND);

			Bullet* bullet;//set direction of bullet 
			bullet = dynamic_cast<Bullet*>(m_unControllerObj[m_unControllerObj.size() - 1].get());
			bullet->setDireation(player->getLastDirection());
		}

		else GameSound::instance().soundEffects(EMPTY_STACK_SOUND);

	}
	bulletsRegulator++;
	
} 
//-------------moveUnconrollerPlayer-------------
void Map::moveUnconrollerPlayer(const float& deltaTime) {

	for (size_t i = 0; i < m_unControllerObj.size(); i++)
		m_unControllerObj[i]->move(deltaTime);
}
//-------------drawMap------------
void Map::drawMap(sf::RenderWindow& window, const float &deltaTime) {

	window.clear();
	window.draw(m_gameBG);

	m_gameTime.drawTime(window);

	//if created explosion on map as result from 
	//collision with terrorist ,so dont draw the player
	if(!m_player->isDisposed())
		m_player->draw(window);

	drawUnControllerAndStatic(window, deltaTime);

	Player* player;
	player = dynamic_cast<Player*>(m_player.get());

	m_infoLevel.draw(window,player->getBullets(),m_stage,player->getLives(), player->getStars());
	window.display();
}
//--------drawUnControllerAndStatic-------------------
void Map::drawUnControllerAndStatic(sf::RenderWindow& window, const float& deltaTime) const {

	for (size_t i = 0; i < m_unControllerObj.size(); i++)
		m_unControllerObj[i]->draw(window);

	for (size_t i = 0; i < m_staticObj.size(); i++) {
		m_staticObj[i]->updateAni(deltaTime);
		m_staticObj[i]->draw(window);
	}
}
//The function gets tile that presents tool on mapand inserts
//to the appropriate  vector by "factory design patterns"
//-----------insertPlayer------------------
void Map::insertPlayer(const char& tile,const sf::Vector2f & pos) {
	
	if (isupper(tile)) {//unControllerObj players
		m_unControllerObj.emplace_back(Factory<UnControllerObj>::create(tile));
		m_unControllerObj[m_unControllerObj.size() - 1]->setTilePosition(pos);
	}

	else if (isdigit(tile)) {//Controller players
		m_player = Factory<ControllerObj>::create(tile);
		m_player->setTilePosition(pos);
		m_player->setLives(m_lives);
	}

	else if (islower(tile)) {//static players
		m_staticObj.emplace_back(Factory<StaticObject>::create(tile));
		m_staticObj[m_staticObj.size() - 1]->setTilePosition(pos);
	}
}
//The function retuns true if the time over and decrease  lives  
//----------isTimeOver-----------
bool Map::isTimeOver()  {
	
	if (m_gameTime.getTime() < TIME_OVER) {
		m_lives--;
		return true;
	}
	return false;
}
//-----------openFileMap----------------------
void Map::openFileMap() {

	m_fileMaps.open("Board.txt");//open file
	if (!m_fileMaps.is_open()) 
		throw std::runtime_error("Cannot open  file");
}

//----------------constructor-----------------------
Map::Map(){

	m_gameBG.setTexture(*GameTexture::instance().getBG(GAME_BG));
	openFileMap();
}

//-----------setPositionOfInfo----------------
void Map::setPositionOfInfo(const float & x) {
	
	m_infoLevel.setInformationPos(x - (float)SCREEN_W/2);
	m_gameBG.setPosition(x- (float)SCREEN_W / 2, 0);
	m_gameTime.setTimePosition(x- (float)SCREEN_W / 2);
}

//--------------isGameOver-------------------
bool Map::isGameOver() const {

	return m_gameOver;
}

//--------------getStage---------------------
int Map::getStage() const {

	return m_stage;
}
//----------startLevelTime-------------------
void Map::startLevelTime() {

	m_gameTime.startTime(m_stage);
}
//-----------getCurrentLevel-----------------
unsigned Map::getCurrentLevel() const {

	return m_stage;
}

//The function resets the position of background and information
//----------resetPositionOfinfo-------------
void Map::resetPositionOfinfo() {

	m_gameBG.setPosition(0, 0);
	m_infoLevel.resetPosition();
	m_gameTime.resetPosition();
}

//----------getPlayerPosition-------------
const sf::Vector2f& Map::getPlayerPosition() const {
	return m_player->getSprite().getPosition();
}
