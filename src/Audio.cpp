#include "Audio.h"

Audio::Audio(sf::SoundBuffer* soundBuffer)
{
	initMusic(soundBuffer);
}

//-----------------------------------------------------------------

Audio::~Audio()
{
}

//-----------------------------------------------------------------

void Audio::stopPlayMusic()
{
	m_sound.pause();
}

//-----------------------------------------------------------------

void Audio::playMusic(int volume, bool loop)
{
	m_sound.setLoop(loop);
	m_sound.setVolume(volume);
	m_sound.play();
}

//-----------------------------------------------------------------

void Audio::initMusic(sf::SoundBuffer* soundBuffer)
{
	m_sound.setBuffer(*soundBuffer);
}
