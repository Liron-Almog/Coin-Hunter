#include "Wall.h"
#include "GameTexture.h"
#include "Const.h"
Wall::Wall()
{
	m_sprite.setTexture(*GameTexture::instance().getTexturOfPlayers(WALL));	
}