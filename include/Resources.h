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
	sf::Texture* getBackground(ScreenType index);
	sf::Texture* getHelpBackground();
	sf::Texture* getSettingsReturnTexture(ScreenType s);
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
	sf::Texture* getHighScoreBtn();
	sf::Image* getGameIcon();
    sf::Texture* getEndLevelBtnsTexture(EndLevelButtonType b);

	sf::SoundBuffer* getAudioClick();
	sf::SoundBuffer* getAudioWin();
	sf::SoundBuffer* getAudioLose();
	sf::SoundBuffer* getDoorSound();

	void playMusic(ScreenType s);
	bool isMusicOn() const;
	bool isAudioOn() const;

	void switchMusicStatus(ScreenType s);
	void switchAudioStatus();

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	void loadResources();

	//Load Functions
	void loadFont();

	//Textures
	void loadSettingsReturnTexture();
	void loadSettingsHomeTexture();
	void loadBackArrowTexture();

    void loadWinBackground();
	void loadHelpBackground();
    void loadEndLevelBtnsTexture();

	void loadPlayersFace();
	void loadObjects();
	void loadPlayerArrow();
	void loadSign();
	void loadBackgroundTextures();
	void loadLevelMenuIcons();
	void loadHomePageBtnsTexture();
	void loadLevelActionButtonTexture();
	void loadGrounds();
	void loadHighScoreBtn();
	void loadSoundTexture();
	void loadSettingsBackground();

	void loadPlayerSpriteSheet();

	void loadGameIcon();

	//Audio 
	void loadMusic();
	void loadAudioClick();
	void loadAudioWin();
	void loadAudioLose();
	void loadDoorSound();

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
	sf::Texture m_helpBackground;
	sf::Texture m_winBackground;
    sf::Texture m_nextLevelBtn;
    sf::Texture m_retryBtn;
	sf::Texture m_menuBtn;
	sf::Texture m_highScoreBtn;
	std::vector<sf::Texture> m_playersFace;
	std::vector<sf::Texture> m_objects;
	std::vector<sf::Texture> m_grounds;
	std::vector<sf::Texture> m_levelMenuTexture;
	std::vector<sf::Texture> m_homePageBtnsTexture;
	std::vector<sf::Texture> m_endLevelBtnsTexture;
	std::vector<sf::Texture> m_levelActionButtonsTexture;
	std::vector<sf::Texture> m_backgroundTextures;
	std::vector<sf::Texture> m_playerSpriteSheet;

	std::vector<sf::Texture> m_soundTextures;

	sf::Image m_gameIcon;

	////Audio
	sf::SoundBuffer m_audioClick;
	sf::SoundBuffer m_audioWin;
	sf::SoundBuffer m_audioLose;
	sf::SoundBuffer m_doorSound;

	sf::Music m_gameMusic; //game background music
	sf::Music m_homeMusic; //home background music

	bool m_audioOn = true;
};