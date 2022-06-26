#pragma once
#include <SFML/Audio.hpp>
#include "Const.h"
class GameSound
{
public:
	
	~GameSound() =default;
	static GameSound& instance();
	void soundEffects(const int&);
	void playMenuMusic(const int& );
	void pauseMenuMusic(const int& );
	

private:
	GameSound();
	GameSound(const GameSound&) = default;
	GameSound & operator=(const GameSound&) = default;
	sf::SoundBuffer m_soundEffectsBuf[SOUND_EFFECTS];
	sf::Sound m_soundEffects[SOUND_EFFECTS];
	sf::Music m_music[NUMBER_OF_MUSIC];

};

