#include "Factory.h"
#include "Wall.h"
#include "Enemy.h"
#include "Player.h"
#include "Star.h"
#include "Door.h"
#include "Fire.h"
#include "StartFlag.h"
#include "Bullet.h"
#include "Tree.h"
#include "Explosion.h"
#include "StaticBullet.h"
#include "Heart.h"


bool Wall::m_registerit = Factory<StaticObject>::registerit(WALL_SIGN,
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Wall>(); });

bool Enemy::m_registerit = Factory<UnControllerObj>::registerit(ENEMY_SIGN,
	[]() -> unique_ptr<UnControllerObj> { return std::make_unique<Enemy>(); });

bool Player::m_registerit = Factory<ControllerObj>::registerit(PLAYER_SIGN,
	[]() -> unique_ptr<ControllerObj> { return std::make_unique<Player>(); });

bool Star::m_registerit = Factory<StaticObject>::registerit(STAR_SIGH,
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Star>(); });

bool Door::m_registerit = Factory<StaticObject>::registerit(DOOR_SIGH,
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Door>(); });

bool Fire::m_registerit = Factory<StaticObject>::registerit(FIRE_SIGN,
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Fire>(); });

bool StartFlag::m_registerit = Factory<StaticObject>::registerit(START_FLAG_SIGN,
	[]() -> unique_ptr<StaticObject> { return std::make_unique<StartFlag>(); });

bool Bullet::m_registerit = Factory<UnControllerObj>::registerit(BULLET_SIGN,
	[]() -> unique_ptr<UnControllerObj> { return std::make_unique<Bullet>(); });

bool Tree::m_registerit = Factory<StaticObject>::registerit(TREE_SGIN,
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Tree>(); });

bool StaticBullet::m_registerit = Factory<StaticObject>::registerit(STATIC_BULLET_SIGN,
	[]() -> unique_ptr<StaticObject> { return std::make_unique<StaticBullet>(); });

bool Explosion::m_registerit = Factory<StaticObject>::registerit(EXPLOSION_SIGN,
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Explosion>(); });

bool Heart::m_registerit = Factory<StaticObject>::registerit(HEART_SIGN,
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Heart>(); });