#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Macros.h"


class Audio {
public:
	Audio(sf::SoundBuffer* soundBuffer);
	Audio() = default;
	~Audio();

	void playAudio(int volume = 10, bool loop = false);
	void stop();

private:
	sf::Sound m_sound;
};