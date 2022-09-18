#include "StaticBullet.h"
#include "Const.h"
#include "GameTexture.h"
StaticBullet::StaticBullet()
{
	m_sprite.setTexture(*GameTexture::instance().getInformaionTexture(BULLET_INFO));

}
