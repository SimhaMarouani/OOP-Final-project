#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Macros.h"
#include "Utilities.h"


class Resources
{
public:
	~Resources();
	static Resources& instance();

	//Access Functions
	sf::Font* getFont();
	sf::Texture* getBackground(Screen index);
	sf::Texture* getPlayerTexture(Player player);
	sf::Texture* getSettingsReturnTexture();
	sf::Texture* getSettingsHomeTexture();
	sf::Texture* getPlayerFaceTexture(Player player);
	sf::Texture* getPlayerArrowTexture();
	sf::Texture* getObjectTexture(Objects obj);
	sf::Texture* getLevelMenuTexture(LevelState l);
	sf::Texture* getHomePageBtnsTexture(HomeButtonType b);
	sf::Texture* getLevelActionButtonTexture(LevelActions la);
	sf::Texture* getGroundTexture(Grounds obj);
	sf::Texture* getSoundTexture(SoundStatus s);
	sf::Texture* getSettingsBackground();

	void playMusic(Screen s);
	bool isMusicOn() const;

	void switchMusicStatus(Screen s);
private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//Load Functions
	void loadFont();

	//Textures
	void loadPlayers();
	void loadSettingsReturnTexture();
	void loadSettingsHomeTexture();

	void loadPlayersFace();
	void loadObjects();
	void loadPlayerArrow();
	void loadBackgroundTextures();
	void loadLevelMenuIcons();
	void loadHomePageBtnsTexture();
	void loadLevelActionButtonTexture();
	void loadGrounds();

	void loadSoundTexture();
	void loadSettingsBackground();

	
	//Audio 
	void loadMusic();

	//======Members==========

	//Fonts
	sf::Font m_font;

	////Textures
	sf::Texture m_playerArrow;;
	sf::Texture m_settingsReturnTexture;
	sf::Texture m_settingsHomeTexture;
	sf::Texture m_settingsBackground;
	std::vector<sf::Texture> m_players;
	std::vector<sf::Texture> m_playersFace;
	std::vector<sf::Texture> m_objects;
	std::vector<sf::Texture> m_grounds;
	std::vector<sf::Texture> m_levelMenuTexture;
	std::vector<sf::Texture> m_homePageBtnsTexture;
	std::vector<sf::Texture> m_levelActionButtonsTexture;
	std::vector<sf::Texture> m_backgroundTextures;

	std::vector<sf::Texture> m_soundTextures;

	////Audio
	//sf::SoundBuffer m_audioClick;

	sf::Music m_gameMusic; //game background music
	sf::Music m_homeMusic; //home background music
	//const std::string MUSIC_FILE_NAME[NUM_OF_BG_TEXTURES] = { "home_music.wav", "levelmenu_music.wav", "birds.wav" };
	//std::vector<sf::Music> m_music;
};