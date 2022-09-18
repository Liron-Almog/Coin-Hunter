#include "Door.h"
#include "GameTexture.h"
Door::Door()
{
	m_sprite.setTexture(*GameTexture::instance().getTexturOfPlayers(DOOR));

}
