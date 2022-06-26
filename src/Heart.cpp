#include "Heart.h"
#include "GameTexture.h"
#include "Const.h"
Heart::Heart()
{
	m_sprite.setTexture(*GameTexture::instance().getTexturOfPlayers(HEART));
	
}