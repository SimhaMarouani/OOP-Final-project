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
	sf::Texture* getSettingsReturnTexture(Screen s);
	sf::Texture* getSettingsHomeTexture();
    sf::Texture* getBackArrowTexture();
    sf::Texture* getPlayerFaceTexture(Player player);
	sf::Texture* getPlayerArrowTexture();
	sf::Texture* getSignTexture();
	sf::Texture* getObjectTexture(Objects obj);
	sf::Texture* getLevelMenuTexture(LevelState l);
	sf::Texture* getHomePageBtnsTexture(HomeButtonType b);
	sf::Texture* getLevelActionButtonTexture(LevelActions la);
	sf::Texture* getGroundTexture(Grounds obj);
	sf::Texture* getSoundTexture(SoundStatus s);
	sf::Texture* getSettingsBackground();
	sf::Texture* getPlayerSpriteSheet(Player p);
    sf::Texture* getWinBackground();
    sf::Texture* getNextLevelBtn();
    sf::Texture* getRetryBtn();
    sf::Texture* getMenuBtn();
	sf::Image* getGameIcon();

	sf::SoundBuffer* getAudioClick();

	void playMusic(Screen s);
	bool isMusicOn() const;
	bool isAudioOn() const;

	void switchMusicStatus(Screen s);
	void switchAudioStatus();
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
	void loadBackArrowTexture();

    void loadWinBackground();
    void loadNextLevelBtn();
    void loadRetryBtn();
    void loadMenuBtn();

	void loadPlayersFace();
	void loadObjects();
	void loadPlayerArrow();
	void loadSign();
	void loadBackgroundTextures();
	void loadLevelMenuIcons();
	void loadHomePageBtnsTexture();
	void loadLevelActionButtonTexture();
	void loadGrounds();

	void loadSoundTexture();
	void loadSettingsBackground();

	void loadPlayerSpriteSheet();

	void loadGameIcon();

	//Audio 
	void loadMusic();
	void loadAudioClick();

	//======Members==========

	//Fonts
	sf::Font m_font;

	////Textures
	sf::Texture m_playerArrow;;
	sf::Texture m_backArrow;;
	sf::Texture m_sign;;
	std::vector<sf::Texture> m_settingsReturnTexture;
	sf::Texture m_settingsHomeTexture;
	sf::Texture m_settingsBackground;
	sf::Texture m_winBackground;
    sf::Texture m_nextLevelBtn;
    sf::Texture m_retryBtn;
    sf::Texture m_menuBtn;
	std::vector<sf::Texture> m_players;
	std::vector<sf::Texture> m_playersFace;
	std::vector<sf::Texture> m_objects;
	std::vector<sf::Texture> m_grounds;
	std::vector<sf::Texture> m_levelMenuTexture;
	std::vector<sf::Texture> m_homePageBtnsTexture;
	std::vector<sf::Texture> m_levelActionButtonsTexture;
	std::vector<sf::Texture> m_backgroundTextures;
	std::vector<sf::Texture> m_playerSpriteSheet;

	std::vector<sf::Texture> m_soundTextures;

	sf::Image m_gameIcon;

	////Audio
	sf::SoundBuffer m_audioClick;

	sf::Music m_gameMusic; //game background music
	sf::Music m_homeMusic; //home background music
	//const std::string MUSIC_FILE_NAME[NUM_OF_BG_TEXTURES] = { "home_music.wav", "levelmenu_music.wav", "birds.wav" };
	//std::vector<sf::Music> m_music;

	bool m_audioOn = true;
};