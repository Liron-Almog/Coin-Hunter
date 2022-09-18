#include "StartFlag.h"
#include "GameTexture.h"
#include "Const.h"

StartFlag::StartFlag()
{
	m_sprite.setTexture(*GameTexture::instance().getTexturOfPlayers(START_FLAG));

}
