#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <memory>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <map>
#include <iterator>
#include <cstdlib>
#include <typeinfo>
#include <stdexcept>
#include <typeindex>
class GameObject;


//----------------------------using-----------------------
using HitFunctionPtr = void (*)(GameObject&, GameObject&);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::unique_ptr;
using std::map;
//----------------------------enums-----------------------
enum gameBG_t {

	MENU_BG,
	GAME_BG,
	INFORMATION,
	BG_NUMBER
};

enum gameFont_t {

	CANDY_FONT,
	ASDONUTS_FONT,
	FONTINFO_FONT,
	DIGITAL_FONT,
	FONT_NUMBER
};

enum transitionScreens_t {

	NEXT_LEVEL,
	GAME_OVER_BG,
	TIME_IS_OVER,
	START,
	QUIT,
	TRANSITION_SCREENS
};
enum inFormaionIcons {
	HEART_INFO,
	BULLET_INFO,
	STAR_INFO,
	NUMBER_OF_ICON_INFO
};


enum players_t {
	WALL,
	PLAYER,
	STAR,
	FIRE,
	BOMB,
	DOOR,
	ENEMY,
	START_FLAG,
	BULLET,
	TREE,
	STATIC_BULLET,
	HEART,
	NUMBER_OF_OBJECT
};
enum animation_t {
	EXPLOSION,
	NUMBER_OF_ANIMATION
};
enum soundEffects_t {
	SELECT_SOUND,
	COLLECTED_SOUND,
	COLLISION_SOUND,
	DEC_LIVE_SOUND,
	UNLOCK_SOUND,
	WIN_LEVEL_SOUND,
	SHOT_SOUND,
	EXPLOSION_SOUND,
	COLLECTED_HEART_SOUND,
	EMPTY_STACK_SOUND,
	SOUND_EFFECTS
};

enum information_t {
	LIVES,
	STARS,
	BULLETS,
	STAGE,
	TEXT_OF_STAGE,
	NUBER_OF_INFO
};

enum music_t {
	MENU_MUSIC,
	GAME_MUSIC,
	NUMBER_OF_MUSIC
};
//--------------------------consts--------------------------
const int SCREEN_H = 800,
	SCREEN_W = 1600,
	SHOW_TIME = 2,
	NUM_OF_DIRECTIONS = 4,
	MAXIMUM_TIME = 500,
	SIZE_MAP_R = 17,
	DECREASE_TIME = -90,
	SIZE_MAP_C = 91,
	GAME_OVER = 0,
	FIRST_STAGE = 1,
	NO_OPTION = -1,
	WALL_SIZE = 50,
	TIME_OVER = 1,
	SHOW_EXPOSION = 100,
	COLS_NUM_ANI_EXPLOSION = 8,
	ROWS_NUM_ANI_EXPLOSION = 6,
	COLS_NUM_ANI_FIRE = 4,
	ROWS_NUM_ANI_FIRE = 2,
	ROWS_NUM_ANI_ENEMY = 4,
	COLS_NUM_ANI_ENEMY = 4,
	ROWS_NUM_ANI_STAR = 1,
	COLS_NUM_ANI_STAR = 5,
	MAXIMUM_FPS = 60,
	MAXIMUM_BULLETS = 10,
	BULLET_SPEED = 110,
	REGULATOR_6 = 6,
	MAX_BULLETS = 10;

const float PLAYER_SPEED = 210,
	TIME_BET_ANI_PLAYER = 0.07,
	TIME_BET_ANI_FIRE = 0.25, 
	TIME_BET_ANI_EXPLSION = 0.25,
	TIME_BET_ANI_ENEMY = 0.1,
	TIME_BET_ANI_STAR = 0.4f,
	SCREENÉ_LENGHT = 4500,
	MAXIMUM_DELTA_TIME = 1.0,
	ENEMY_SPEED = 150;



const unsigned MAXIMUM_STAR = 8,
				MAXIMUM_LIVES = 3,
				COLS_NUM_ANI_PLAYER = 7,
				ROWS_NUM_ANI_PLAYER = 4;

const string START_S = "Start";

const sf::Vector2f LIVES_TEXT_POS = sf::Vector2f(85, 27 + 45),
					STARS_TEXT_POS = sf::Vector2f(355, 27 + 45),
					BULLETS_TEXT_POS = sf::Vector2f(1220, 27 + 45),
					STAGE_TEXT_POS = sf::Vector2f(1058, 27 + 45),
					POS_STAGE_BAR = sf::Vector2f(70, 800 - 145),
					POS_TIME_BAR = sf::Vector2f(880, 27 + 45),
					TEXT_POS_TIME = sf::Vector2f(960, 25 + 45),
					UP = sf::Vector2f(0, (float)(-1))
					, LEFT = sf::Vector2f((float)-1, 0)
					, RIGHT = sf::Vector2f((float)1, 0)
					, STAND = sf::Vector2f(0, 0)
					, DOWN = sf::Vector2f(0, (float)(1));


