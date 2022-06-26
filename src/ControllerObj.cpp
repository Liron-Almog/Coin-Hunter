#include "ControllerObj.h"
#include "GameSound.h"
//-----------getLives---------------
const unsigned ControllerObj::getLives() const {
	return m_lives;
}

//-----------setLives---------------
void ControllerObj::setLives( const unsigned & num) {
    m_lives = num;
}
//-----------decLive---------------
void ControllerObj::decLive() {

	if (m_lives > 0)
		m_lives--;
}
//-----incLives--------
void ControllerObj::incLives() {

	if (m_lives < MAXIMUM_LIVES) {
		GameSound::instance().soundEffects(COLLECTED_HEART_SOUND);
		m_lives++;
	}
	
}