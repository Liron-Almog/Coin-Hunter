#pragma once
#include "Const.h"
#include <fstream>
#include "StaticObject.h"
#include "ControllerObj.h"
#include "UnControllerObj.h"
#include "GameTime.h"
#include "CollisionHandling.h"
#include "InfoLevel.h"
class Map
{
public:

	void specialEventsWithStaticObj();
	void setGameStart();
	void readMapOrGameOver();
	void drawUnControllerAndStatic(sf::RenderWindow& window, const float& deltaTime) const ;
	void unControlledObjWithThemSelves();
	void shot();
	void specialEventsWithUnControllerObj(sf::RenderWindow& , const float& );
	void deleteDisposedObj();
	void controllerdObjWithOthers();
	bool isColiistion(const GameObject&,const GameObject const &);
	void unControlledObjWithStatic();
	void checkCollistion(sf::RenderWindow& window , const float& deltaTime);
	bool isGameOver() const;
	void startLevelTime();
	int getStage() const;
	Map();

	const sf::Vector2f& getPlayerPosition() const;
	bool isTimeOver();
	void resetPositionOfinfo();
	void specialEventsCuzColistion(sf::RenderWindow& window, const float& deltaTime);
	void moveUnconrollerPlayer(const float& deltaTime);
	void setPositionOfInfo(const float&);
	virtual ~Map() = default;
	void readMap(bool newLevel);
	void drawMap(sf::RenderWindow &window , const float& deltaTime);
	void insertPlayer(const char& tile, const sf::Vector2f& pos);
	void movePlayer(const sf::Vector2f &direction,const float& deltaTime);
	unsigned getCurrentLevel() const;
	void readMapFromFile();
	bool isGameStart() const;

private:
	void clearArray();
	void openFileMap();

	std::fstream m_fileMaps;
	CollisionHandling m_collisionHandling;
	InfoLevel m_infoLevel;
	unsigned m_lives = 3;
	bool m_gameOver = false,
		m_gameStart = false;;
	sf::Sprite m_gameBG;
	unsigned m_stage;
	GameTime m_gameTime;
	vector<unique_ptr<StaticObject>> m_staticObj;
	unique_ptr<ControllerObj> m_player;
	vector<unique_ptr<UnControllerObj>> m_unControllerObj;
};
