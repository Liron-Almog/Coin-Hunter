#include "CollisionHandling.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Wall.h"
#include "Player.h"
#include "Fire.h"
#include "Star.h"
#include "GameSound.h"
#include "Bullet.h"
#include "StaticBullet.h"
#include "Door.h"
#include "GameSound.h"
#include "Heart.h"

//The function handles a collision of Wall and Enemy
//--------------wallEnemy--------------------
void wallEnemy(GameObject & gameObject1,GameObject & gameObject2)
{
    
    Enemy & enemyObj = static_cast<Enemy&>(gameObject1);
    enemyObj.changeDirection();
}
//The function handles a collision of Wall and Bullet
//--------------bulletWall--------------------
void bulletWall(GameObject& gameObject1, GameObject& gameObject2) 
{

    Bullet& bullet = static_cast<Bullet&>(gameObject1);
    bullet.setDisposed();
}
//The function handles a collision of Wall and Player
//--------------wallPlayer--------------------
void wallPlayer(GameObject& gameObject1, GameObject& gameObject2) 
{

    Player& player = static_cast<Player&>(gameObject1);
    GameSound::instance().soundEffects(COLLISION_SOUND);
    player.moveStepBack();
    
}
//The function handles a collision of Heart and Player
//--------------playerHeart--------------------
void playerHeart(GameObject& gameObject1, GameObject& gameObject2) 
{

    Player& player = static_cast<Player&>(gameObject1);
    Heart& heart = static_cast<Heart&>(gameObject2);
    player.incLives();
    heart.setDisposed();
 
}\
//The function handles a collision of Fire and Player
//--------------firePlayer--------------------
void firePlayer(GameObject& gameObject1, GameObject& gameObject2)
{

    GameSound::instance().soundEffects(DEC_LIVE_SOUND);
    Player& player = static_cast<Player&>(gameObject1);
    player.setDisposed();
    player.decLive();
}
//The function handles a collision of Star and Player
//--------------starPlayer--------------------
void starPlayer(GameObject& gameObject1, GameObject& gameObject2)
{
    Player& player = static_cast<Player&>(gameObject1);
    Star& star = static_cast<Star&>(gameObject2);

    if(player.getStars() == 1)
        GameSound::instance().soundEffects(UNLOCK_SOUND);
    else GameSound::instance().soundEffects(SELECT_SOUND);

    player.decStars();
    star.setDisposed();
}
//The function handles a collision of Enemy and Player
//--------------enemyPlayer--------------------
void enemyPlayer(GameObject& gameObject1, GameObject& gameObject2)
{
    Player& player = static_cast<Player&>(gameObject1);
    Enemy& enemyObj = static_cast<Enemy&>(gameObject2);
    enemyObj.setDisposed();
    player.setDisposed();
    player.decLive();
}
//The function handles a collision of Enemy and Bullet
//--------------bulletEnemy--------------------
void bulletEnemy(GameObject& gameObject1, GameObject& gameObject2){
  
    Enemy& enemyObj = static_cast<Enemy&>(gameObject2);
    Bullet& bullet = static_cast<Bullet&>(gameObject1);

    enemyObj.setDisposed();
    bullet.setDisposed();
  
}
//The function handles a collision of Player and StaticBullet
//--------------playerStaticBullet--------------------
void playerStaticBullet(GameObject& gameObject1, GameObject& gameObject2){

    Player& player = static_cast<Player&>(gameObject1);
    StaticBullet& staticBullet = static_cast<StaticBullet&>(gameObject2);

    staticBullet.setDisposed();
    player.incBullet();
}
//The function handles a collision of Player and Door
//--------------playerDoor-------------------
void playerDoor(GameObject& gameObject1, GameObject& gameObject2)
{
    Player& player = static_cast<Player&>(gameObject1);
    Door& door = static_cast<Door&>(gameObject2);

    player.moveStepBack();
    if (player.getStars() == 0) 
        door.setDisposed();
    
}
//The function searchs function that gets two obj 
//--------------processCollision--------------------
void CollisionHandling::processCollision(GameObject& object1, GameObject& object2) {

    auto phf = lookUp(typeid(object1), typeid(object2));
        if (phf)
             phf(object1, object2);

}
//--------------Constructor--------------------
CollisionHandling::CollisionHandling()
{

   m_collisionMap[Key(typeid(Enemy), typeid(Wall))] = &wallEnemy;
    m_collisionMap[Key(typeid(Bullet), typeid(Wall))] = &bulletWall;
    m_collisionMap[Key(typeid(Bullet), typeid(Enemy))] = &bulletEnemy;
    m_collisionMap[Key(typeid(Bullet), typeid(Door))] = &bulletWall;
    m_collisionMap[Key(typeid(Player), typeid(Wall))] = &wallPlayer;
    m_collisionMap[Key(typeid(Player), typeid(Fire))] = &firePlayer;
    m_collisionMap[Key(typeid(Player), typeid(Star))] = &starPlayer;
    m_collisionMap[Key(typeid(Player), typeid(Enemy))] = &enemyPlayer;
    m_collisionMap[Key(typeid(Player), typeid(StaticBullet))] = &playerStaticBullet;
    m_collisionMap[Key(typeid(Player), typeid(Door))] = &playerDoor;
    m_collisionMap[Key(typeid(Player), typeid(Heart))] = &playerHeart;
    m_collisionMap[Key(typeid(Enemy), typeid(Fire))] = &wallEnemy;
    m_collisionMap[Key(typeid(Enemy), typeid(Door))] = &wallEnemy;
    m_collisionMap[Key(typeid(Enemy), typeid(Star))] = &wallEnemy;
}

//The function searches for the two objects sent to it 
//within the data structure and if it finds it activates 
//the required function otherwise returns null
//----------------lookUp-------------------------
HitFunctionPtr CollisionHandling::lookUp(const std::type_index& class1, const std::type_index& class2)
{

    auto mapEntry = m_collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == m_collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}