#include "Tree.h"
#include "GameTexture.h"
#include "Const.h"

Tree::Tree()
{
	m_sprite.setTexture(*GameTexture::instance().getTexturOfPlayers(TREE));
}