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

bool Wall::m_registerit = Factory<StaticObject>::registerit('w',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Wall>(); });

bool Enemy::m_registerit = Factory<UnControllerObj>::registerit('X',
	[]() -> unique_ptr<UnControllerObj> { return std::make_unique<Enemy>(); });

bool Player::m_registerit = Factory<ControllerObj>::registerit('1',
	[]() -> unique_ptr<ControllerObj> { return std::make_unique<Player>(); });

bool Star::m_registerit = Factory<StaticObject>::registerit('s',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Star>(); });

bool Door::m_registerit = Factory<StaticObject>::registerit('d',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Door>(); });

bool Fire::m_registerit = Factory<StaticObject>::registerit('f',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Fire>(); });

bool StartFlag::m_registerit = Factory<StaticObject>::registerit('m',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<StartFlag>(); });

bool Bullet::m_registerit = Factory<UnControllerObj>::registerit('B',
	[]() -> unique_ptr<UnControllerObj> { return std::make_unique<Bullet>(); });

bool Tree::m_registerit = Factory<StaticObject>::registerit('t',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Tree>(); });

bool StaticBullet::m_registerit = Factory<StaticObject>::registerit('b',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<StaticBullet>(); });

bool Explosion::m_registerit = Factory<StaticObject>::registerit('e',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Explosion>(); });

bool Heart::m_registerit = Factory<StaticObject>::registerit('h',
	[]() -> unique_ptr<StaticObject> { return std::make_unique<Heart>(); });