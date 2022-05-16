#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Macros.h"


class Audio {
public:
	Audio(sf::SoundBuffer* soundBuffer);
	~Audio();

	void playMusic(int volume = 10, bool loop = false);
	void stopPlayMusic();

private:
	//functions
	void initMusic(sf::SoundBuffer* soundBuffer);
	sf::Sound m_sound; //for use of small sounds like collisions and such
	//sf::Music m_music; //for use of long term sounds like background music (also allows looping of music)
};