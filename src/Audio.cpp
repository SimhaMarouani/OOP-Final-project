#include "Audio.h"

Audio::Audio(sf::SoundBuffer* soundBuffer)
{
	m_sound.setBuffer(*soundBuffer);
}

//-----------------------------------------------------------------

Audio::~Audio()
{
}

//-----------------------------------------------------------------

void Audio::stop()
{
	m_sound.pause();
}

//-----------------------------------------------------------------

void Audio::playAudio(int volume, bool loop)
{
	if (!Resources::instance().isAudioOn()) return;
	m_sound.setLoop(loop);
	m_sound.setVolume(volume);
	m_sound.play();
}
