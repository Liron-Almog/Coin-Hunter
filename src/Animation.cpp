#include "Animation.h"
//-------------Constructor--------------------
Animation::Animation(const sf::Texture & texture, sf::Vector2u imageCount, float switchTime)
{
	m_imageCount = imageCount;
	m_switchTime = switchTime;
	m_totalTime = 0.0f;
	m_currentImage.x = 0;

	m_uvRect.width = texture.getSize().x / float(m_imageCount.x);
	m_uvRect.height = texture.getSize().y / float(m_imageCount.y);
}
//------------get_uvRect---------------
const sf::IntRect* Animation::get_uvRect() const {
	return  &m_uvRect;
}
//The function updates the animation to next image
//-------------update----------
void Animation::update(const unsigned& row, const float& deltaTime) {

	m_currentImage.y = row;
	m_totalTime += deltaTime;

	if (m_totalTime >= m_switchTime) {
		m_totalTime -= m_switchTime;
		m_currentImage.x++;
		m_currentImage.x %= m_imageCount.x;//returns to col start
	}
	//calculates the required image
	m_uvRect.left = m_currentImage.x * m_uvRect.width;
	m_uvRect.top = m_currentImage.y * m_uvRect.height;

}
//----------------getCurrentImage-----------
const sf::Vector2u& Animation::getCurrentImage() const {
	return m_currentImage;
}
//--------------setCurrentRow--------------
void Animation::setCurrentRow(const unsigned& newRow) {
	m_currentImage.y = newRow;
}
//----------------getImageCount--------------
const sf::Vector2u& Animation::getImageCount() const {
	return m_imageCount;
}
//The function gets direction and returns the number of row of animation 
//---------getRowOfStandatAni------------
unsigned Animation::getRowOfStandatAni(const sf::Vector2f& dir) const {

	if (dir == RIGHT)
		return 2;
	else if (dir == LEFT)
		return 1;
	else if (dir == DOWN)
		return 0;
	else if (dir == UP)
		return 3;

	return 0;//DOWN
}