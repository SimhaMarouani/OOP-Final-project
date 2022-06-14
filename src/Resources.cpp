#include "Resources.h"

Resources::Resources()
{
	loadResources();
}

void Resources::loadResources()
{
	try {
		loadFont();
		loadBackgroundTextures();
		loadHelpBackground();
		loadSettingsReturnTexture();
		loadSettingsHomeTexture();
		loadPlayersFace();
		loadPlayerArrow();
		loadSign();
		loadObjects();
		loadGrounds();
		loadLevelMenuIcons();
		loadHomePageBtnsTexture();
		loadLevelActionButtonTexture();
		loadSoundTexture();
		loadSettingsBackground();
		loadPlayerSpriteSheet();
		loadMusic();
		loadBackArrowTexture();
		loadWinBackground();
        loadEndLevelBtnsTexture();
		loadHighScoreBtn();
		loadGameIcon();
		loadAudioClick();
        loadAudioWin();
        loadAudioLose();
		loadDoorSound();
		loadHaySound();
		loadJumpSound();
	}
	catch (const std::logic_error& e)
	{
		std::cerr << "Error loading: " << e.what();
		exit(EXIT_FAILURE);
	}
}

Resources::~Resources()
{
}

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}

//===============================================================//
//						AUDIO FUNCTIONS
//===============================================================//

sf::SoundBuffer* Resources::getAudioClick()
{
	return &m_audioClick;
}

sf::SoundBuffer* Resources::getAudioWin()
{
	return &m_audioWin;
}

sf::SoundBuffer* Resources::getAudioLose()
{
	return &m_audioLose;
}

sf::SoundBuffer* Resources::getDoorSound()
{
	return &m_doorSound;
}

sf::SoundBuffer* Resources::getHaySound()
{
	return &m_haySound;
}

sf::SoundBuffer* Resources::getJumpSound()
{
	return &m_jumpSound;
}

void Resources::playMusic(ScreenType s)
{
	switch (s)
	{
	case ScreenType::Game:
		m_gameMusic.setLoop(true);
		m_gameMusic.play();
		m_homeMusic.pause();
		break;
	case ScreenType::HomePage:
	case ScreenType::LevelMenu:
	{
		if (m_homeMusic.getStatus() == sf::SoundSource::Status::Playing) break;
		m_homeMusic.setLoop(true);
		m_homeMusic.play();
		m_gameMusic.pause();
		break;
	}
	default:
		break;
	}
}

bool Resources::isMusicOn() const
{
	return ( m_gameMusic.getStatus() == sf::SoundSource::Status::Playing || m_homeMusic.getStatus() == sf::SoundSource::Status::Playing ) ;
}

bool Resources::isAudioOn() const
{
	return m_audioOn;
}

void Resources::switchMusicStatus(ScreenType s)
{
	switch (s)
	{
	case ScreenType::Game:
	{
		isMusicOn() ? m_gameMusic.pause() : m_gameMusic.play();
		break;
	}
	case ScreenType::HomePage:
	case ScreenType::LevelMenu:
	{
		isMusicOn() ? m_homeMusic.pause() : m_homeMusic.play();
		break;
	}
	default:
		break;
	}
}

void Resources::switchAudioStatus()
{
	m_audioOn = !m_audioOn;
}

//===============================================================//
//							 GET DATA
//===============================================================//

sf::Font* Resources::getFont()
{
	return &m_font;
}

	
sf::Texture* Resources::getBackground(ScreenType index)
{
	return &m_backgroundTextures[static_cast<int>(index)];
}

sf::Texture* Resources::getHelpBackground()
{
	return &m_helpBackground;
}

sf::Texture* Resources::getWinBackground()
{
    return &m_winBackground;
}

sf::Texture* Resources::getSettingsReturnTexture(ScreenType s)
{
	int i = s == ScreenType::Game ? 0 : 1;
	return &m_settingsReturnTexture[i];
}

sf::Texture* Resources::getSettingsHomeTexture()
{
	return &m_settingsHomeTexture;
}

sf::Texture* Resources::getPlayerFaceTexture(Player player)
{
	return &m_playersFace[static_cast<int>(player)];
}

sf::Texture* Resources::getPlayerArrowTexture()
{
	return &m_playerArrow;
}

sf::Texture* Resources::getSignTexture()
{
	return &m_sign;
}

sf::Texture* Resources::getBackArrowTexture()
{
	return &m_backArrow;
}

sf::Texture* Resources::getObjectTexture(Objects obj)
{
	return &m_objects[static_cast<int>(obj)];
}

sf::Texture* Resources::getGroundTexture(Grounds obj)
{
	return &m_grounds[static_cast<int>(obj)];
}

sf::Texture* Resources::getSoundTexture(SoundStatus s)
{
	return &m_soundTextures[static_cast<int>(s)];
}

sf::Texture* Resources::getSettingsBackground()
{
	return &m_settingsBackground;
}

sf::Texture* Resources::getEndLevelBtnsTexture(EndLevelButtonType b)
{
    return &m_endLevelBtnsTexture[static_cast<int>(b)];
}

sf::Texture* Resources::getHighScoreBtn()
{
	return &m_highScoreBtn;
}

sf::Image* Resources::getGameIcon()
{
	return &m_gameIcon;
}

sf::Texture* Resources::getPlayerSpriteSheet(Player p)
{
	return &m_playerSpriteSheet[static_cast<int>(p)];
}

sf::Texture* Resources::getLevelMenuTexture(LevelState l)
{
	return &m_levelMenuTexture[static_cast<int>(l)];
}

sf::Texture* Resources::getHomePageBtnsTexture(HomeButtonType b)
{
	return &m_homePageBtnsTexture[static_cast<int>(b)];
}

sf::Texture* Resources::getLevelActionButtonTexture(LevelActions la)
{
	return &m_levelActionButtonsTexture[static_cast<int>(la)];
}

//===============================================================//
//							 LOAD DATA
//===============================================================//

void Resources::loadFont()
{
	if (!m_font.loadFromFile("Font.ttf"))
		throw(std::logic_error("Font\n"));
}


void Resources::loadBackgroundTextures()
{
	m_backgroundTextures.resize(NUM_OF_BG_TEXTURES);
	if (!m_backgroundTextures[static_cast<int>(ScreenType::HomePage)].loadFromFile("home_background.png")
		|| !m_backgroundTextures[static_cast<int>(ScreenType::LevelMenu)].loadFromFile("levelmenu_background.png")
		|| !m_backgroundTextures[static_cast<int>(ScreenType::Game)].loadFromFile("game_background.png"))
		throw(std::logic_error("Background Textures\n"));
}

void Resources::loadLevelMenuIcons()
{
	m_levelMenuTexture.resize(2);
	if (!m_levelMenuTexture[static_cast<int>(LevelState::Lock)].loadFromFile("lock_level.png")
		|| !m_levelMenuTexture[static_cast<int>(LevelState::Unlock)].loadFromFile("unlock_level.png"))
		throw(std::logic_error("Level Menu Icons\n"));
}

void Resources::loadHomePageBtnsTexture()
{
	m_homePageBtnsTexture.resize(4);
	if (!m_homePageBtnsTexture[static_cast<int>(HomeButtonType::Start)].loadFromFile("start.png")
		|| !m_homePageBtnsTexture[static_cast<int>(HomeButtonType::Help)].loadFromFile("help.png")
		|| !m_homePageBtnsTexture[static_cast<int>(HomeButtonType::Settings)].loadFromFile("settings.png")
		|| !m_homePageBtnsTexture[static_cast<int>(HomeButtonType::Exit)].loadFromFile("exit.png"))
		throw(std::logic_error("Page Buttons Texture\n"));
}

void Resources::loadEndLevelBtnsTexture()
{
	m_endLevelBtnsTexture.resize(3);
	if (!m_endLevelBtnsTexture[static_cast<int>(EndLevelButtonType::Retry)].loadFromFile("retry_btn.png")
		|| !m_endLevelBtnsTexture[static_cast<int>(EndLevelButtonType::Menu)].loadFromFile("menu_btn.png")
		|| !m_endLevelBtnsTexture[static_cast<int>(EndLevelButtonType::Next)].loadFromFile("next_level_btn.png"))
		throw(std::logic_error("End Buttons Texture\n"));
}

void Resources::loadLevelActionButtonTexture()
{
	m_levelActionButtonsTexture.resize(2);
	if (!m_levelActionButtonsTexture[static_cast<int>(LevelActions::Pause)].loadFromFile("pause_button.png")
		|| !m_levelActionButtonsTexture[static_cast<int>(LevelActions::Retry)].loadFromFile("retry_button.png"))
		throw(std::logic_error("Level Action Button Texture\n"));
}

void Resources::loadSettingsReturnTexture()
{
	m_settingsReturnTexture.resize(2);
	if (!m_settingsReturnTexture[1].loadFromFile("return_button.png")
		|| !m_settingsReturnTexture[0].loadFromFile("continue_button.png")
		)
		throw(std::logic_error("Settings Return Texture\n"));

}

void Resources::loadBackArrowTexture()
{
    if (!m_backArrow.loadFromFile("back_home.png"))
		throw(std::logic_error("Back ArrowTexture\n"));

}

void Resources::loadSettingsHomeTexture()
{
	if (!m_settingsHomeTexture.loadFromFile("home_button.png"))
		throw(std::logic_error("Settings Home Texture\n"));

}

void Resources::loadPlayersFace()
{
	m_playersFace.resize(NUM_OF_PLAYERS);
	if (!m_playersFace[static_cast<int>(Player::Heavy)].loadFromFile("heavy_player_face.png")
		|| !m_playersFace[static_cast<int>(Player::Simple)].loadFromFile("simple_player_face.png")
		|| !m_playersFace[static_cast<int>(Player::Light)].loadFromFile("light_player_face.png"))
		throw(std::logic_error("Players Face\n"));
}

void Resources::loadObjects()
{
	m_objects.resize(NUM_OF_OBJS);

	if (!m_objects[static_cast<int>(Objects::Hay)].loadFromFile("hay.png") 
		|| !m_objects[static_cast<int>(Objects::Rafter)].loadFromFile("rafter.png")
		|| !m_objects[static_cast<int>(Objects::Switch)].loadFromFile("switch.png")
		|| !m_objects[static_cast<int>(Objects::Billboard)].loadFromFile("billboard.png")
		|| !m_objects[static_cast<int>(Objects::SwitchOn)].loadFromFile("switchOn.png"))
		throw(std::logic_error("Objects Texture\n"));
}

void Resources::loadGrounds()
{
	m_grounds.resize(NUM_OF_GROUNDS);

	if (!m_grounds[static_cast<int>(Grounds::Left_l1)].loadFromFile("left_floor_L1.png") ||
		!m_grounds[static_cast<int>(Grounds::Right_l1)].loadFromFile("right_floor_L1.png") ||
		!m_grounds[static_cast<int>(Grounds::l2)].loadFromFile("floor_L2.png") ||
		!m_grounds[static_cast<int>(Grounds::Left_l3)].loadFromFile("left_floor_L3.png") ||
		!m_grounds[static_cast<int>(Grounds::Right_l3)].loadFromFile("right_floor_L3.png")
		|| !m_grounds[static_cast<int>(Grounds::Door)].loadFromFile("door.png")
		|| !m_grounds[static_cast<int>(Grounds::l3)].loadFromFile("floor_L3.png")
		|| !m_grounds[static_cast<int>(Grounds::l4)].loadFromFile("floor_L4.png"))
		throw(std::logic_error("Grounds Texture\n"));
}

void Resources::loadHighScoreBtn()
{
	if (!m_highScoreBtn.loadFromFile("high_scores_button.png"))
		throw(std::logic_error("High Score Button\n"));

}

void Resources::loadSoundTexture()
{
	m_soundTextures.resize(4);

	if (!m_soundTextures[static_cast<int>(SoundStatus::AudioOn)].loadFromFile("audio_on.png") ||
		!m_soundTextures[static_cast<int>(SoundStatus::AudioOff)].loadFromFile("audio_off.png") ||
		!m_soundTextures[static_cast<int>(SoundStatus::MusicOn)].loadFromFile("music_on.png") ||
		!m_soundTextures[static_cast<int>(SoundStatus::MusicOff)].loadFromFile("music_off.png") )
		throw(std::logic_error("Sound Textures\n"));
}

void Resources::loadSettingsBackground()
{
	if (!m_settingsBackground.loadFromFile("settings_bg.png"))
		throw(std::logic_error("Settings Background\n"));

}

void Resources::loadWinBackground()
{
	if (!m_winBackground.loadFromFile("win_background.png"))
		throw(std::logic_error("Win Background\n"));

}

void Resources::loadHelpBackground()
{
	if (!m_helpBackground.loadFromFile("help_background.png"))
		throw(std::logic_error("Help Background\n"));
}

void Resources::loadPlayerSpriteSheet()
{
	m_playerSpriteSheet.resize(NUM_OF_PLAYERS);

	if (!m_playerSpriteSheet[static_cast<int>(Player::Heavy)].loadFromFile("heavy_spritesheet.png") ||
		!m_playerSpriteSheet[static_cast<int>(Player::Simple)].loadFromFile("simple_spritesheet.png") ||
		!m_playerSpriteSheet[static_cast<int>(Player::Light)].loadFromFile("light_spritesheet.png"))
		throw(std::logic_error("Player SpriteSheet\n"));
}

void Resources::loadGameIcon()
{
	if (!m_gameIcon.loadFromFile("Game_icon.jpg"))
		throw(std::logic_error("Game Icon\n"));
}

void Resources::loadMusic()
{
	//Noga: try vector with ptr
	if (!m_gameMusic.openFromFile("birds.wav")
		|| !m_homeMusic.openFromFile("home_music.wav"))
		throw(std::logic_error("Music\n"));

	
	m_gameMusic.setVolume(15);
	m_homeMusic.setVolume(15);
}

void Resources::loadAudioClick()
{
	if (!m_audioClick.loadFromFile("click.wav")) 
		throw(std::logic_error("Audio Click\n"));
}

void Resources::loadAudioWin()
{
	if (!m_audioWin.loadFromFile("win.wav"))
		throw(std::logic_error("Audio win\n"));
}

void Resources::loadAudioLose()
{
	if (!m_audioLose.loadFromFile("lose.wav"))
		throw(std::logic_error("Audio lose\n"));

}

void Resources::loadDoorSound()
{
	if (!m_doorSound.loadFromFile("door.wav"))
		throw(std::logic_error("Audio door\n"));
}

void Resources::loadHaySound()
{
	if (!m_haySound.loadFromFile("hay.wav"))
		throw(std::logic_error("Audio hay\n"));
}
void Resources::loadJumpSound()
{
	if (!m_jumpSound.loadFromFile("jump.wav"))
		throw(std::logic_error("Audio jump\n"));
}

void Resources::loadPlayerArrow()
{
	if (!m_playerArrow.loadFromFile("arrow.png"))
		throw(std::logic_error("Player arrow\n"));
}
void Resources::loadSign()
{
	if (!m_sign.loadFromFile("destination.png"))
		throw(std::logic_error("Destination Sign\n"));
}