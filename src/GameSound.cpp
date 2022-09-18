#include "GameSound.h"

//---------------Constructor-----------------
GameSound::GameSound()
{
	m_soundEffectsBuf[SELECT_SOUND].loadFromFile("click.wav");
	m_soundEffects[SELECT_SOUND].setBuffer(m_soundEffectsBuf[SELECT_SOUND]);

	m_soundEffectsBuf[COLLISION_SOUND].loadFromFile("Collision.wav");
	m_soundEffects[COLLISION_SOUND].setBuffer(m_soundEffectsBuf[COLLISION_SOUND]);

	m_soundEffectsBuf[DEC_LIVE_SOUND].loadFromFile("Declive.wav");
	m_soundEffects[DEC_LIVE_SOUND].setBuffer(m_soundEffectsBuf[DEC_LIVE_SOUND]);

	m_soundEffectsBuf[COLLECTED_SOUND].loadFromFile("Collected.wav");
	m_soundEffects[COLLECTED_SOUND].setBuffer(m_soundEffectsBuf[COLLECTED_SOUND]);

	m_soundEffectsBuf[UNLOCK_SOUND].loadFromFile("Unlock.wav");
	m_soundEffects[UNLOCK_SOUND].setBuffer(m_soundEffectsBuf[UNLOCK_SOUND]);

	m_soundEffectsBuf[WIN_LEVEL_SOUND].loadFromFile("WinLevel.wav");
	m_soundEffects[WIN_LEVEL_SOUND].setBuffer(m_soundEffectsBuf[WIN_LEVEL_SOUND]);

	m_soundEffectsBuf[SHOT_SOUND].loadFromFile("Shot.wav");
	m_soundEffects[SHOT_SOUND].setBuffer(m_soundEffectsBuf[SHOT_SOUND]);

	m_soundEffectsBuf[EXPLOSION_SOUND].loadFromFile("Explosion.wav");
	m_soundEffects[EXPLOSION_SOUND].setBuffer(m_soundEffectsBuf[EXPLOSION_SOUND]);

	m_soundEffectsBuf[COLLECTED_HEART_SOUND].loadFromFile("CollectedHeart.wav");
	m_soundEffects[COLLECTED_HEART_SOUND].setBuffer(m_soundEffectsBuf[COLLECTED_HEART_SOUND]);

	m_soundEffectsBuf[EMPTY_STACK_SOUND].loadFromFile("EmptyStack.wav");
	m_soundEffects[EMPTY_STACK_SOUND].setBuffer(m_soundEffectsBuf[EMPTY_STACK_SOUND]);
	
	m_music[GAME_MUSIC].openFromFile("GameMusic.wav");
	m_music[MENU_MUSIC].openFromFile("MenuMusic.wav");
	m_music[MENU_MUSIC].setVolume(30.f);
	m_music[GAME_MUSIC].setVolume(20.f);
	
}
//-----------------playMenuMusic-----------------
void GameSound::playMenuMusic(const int & num) {

	m_music[num].play();
	m_music[num].setLoop(true);
}
//-----------------pauseMenuMusic-----------------
void GameSound::pauseMenuMusic(const int& num) {

	m_music[num].pause();
	
}
//-----------------soundEffects----------------------
void GameSound::soundEffects(const int & num) {

	m_soundEffects[num].play();

}
//-----------------instance----------------------
GameSound& GameSound::instance() {
	static GameSound inst;
	return inst;
}
