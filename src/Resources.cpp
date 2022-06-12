#include "Resources.h"

sf::SoundBuffer* Resources::getAudioClick()
{
	return &m_audioClick;
}

void Resources::playMusic(Screen s)
{
	switch (s)
	{
	case Screen::Game:
		m_gameMusic.setLoop(true);
		m_gameMusic.play();
		m_homeMusic.pause();
		break;
	case Screen::HomePage:
	case Screen::LevelMenu:
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

void Resources::switchMusicStatus(Screen s)
{
	switch (s)
	{
	case Screen::Game:
	{
		isMusicOn() ? m_gameMusic.pause() : m_gameMusic.play();
		break;
	}
	case Screen::HomePage:
	case Screen::LevelMenu:
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

Resources::Resources()
{
	//Tali: add exceptions to hereee
	loadFont();
	loadBackgroundTextures();
	loadPlayers();
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
    loadNextLevelBtn();
    loadRetryBtn();
    loadMenuBtn();

	loadAudioClick();
}


//-----------------------------------------------------------------

Resources::~Resources()
{
}

//-----------------------------------------------------------------

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}


//===============================================================//
//							 GET DATA
//===============================================================//

sf::Font* Resources::getFont()
{
	return &m_font;
}

//-----------------------------------------------------------------
	
sf::Texture* Resources::getBackground(Screen index)
{
	return &m_backgroundTextures[int(index)];
}

sf::Texture* Resources::getWinBackground()
{
    return &m_winBackground;
}

sf::Texture* Resources::getPlayerTexture(Player player)
{
	return &m_players[(int)player];
}

sf::Texture* Resources::getSettingsReturnTexture(Screen s)
{
	int i = s == Screen::Game ? 0 : 1;
	return &m_settingsReturnTexture[i];
}

sf::Texture* Resources::getSettingsHomeTexture()
{
	return &m_settingsHomeTexture;
}

sf::Texture* Resources::getPlayerFaceTexture(Player player)
{
	return &m_playersFace[(int)player];
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
	return &m_objects[(int)obj];
}

sf::Texture* Resources::getGroundTexture(Grounds obj)
{
	return &m_grounds[(int)obj];
}

sf::Texture* Resources::getSoundTexture(SoundStatus s)
{
	return &m_soundTextures[(int)s];
}

sf::Texture* Resources::getSettingsBackground()
{
	return &m_settingsBackground;
}

sf::Texture* Resources::getNextLevelBtn()
{
    return &m_nextLevelBtn;
}

sf::Texture* Resources::getRetryBtn()
{
    return &m_retryBtn;
}

sf::Texture* Resources::getMenuBtn()
{
    return &m_menuBtn;
}

sf::Texture* Resources::getPlayerSpriteSheet(Player p)
{
	return &m_playerSpriteSheet[(int)p];
}

sf::Texture* Resources::getLevelMenuTexture(LevelState l)
{
	return &m_levelMenuTexture[(int)l];
}

sf::Texture* Resources::getHomePageBtnsTexture(HomeButtonType b)
{
	return &m_homePageBtnsTexture[(int)b];
}

sf::Texture* Resources::getLevelActionButtonTexture(LevelActions la)
{
	return &m_levelActionButtonsTexture[int(la)];
}

//===============================================================//
//							 LOAD DATA
//===============================================================//

void Resources::loadFont()
{
	if (!m_font.loadFromFile("Font.ttf"))
	{
		std::cerr << "error loading font from file";
	}
}

//-----------------------------------------------------------------

void Resources::loadBackgroundTextures()
{
	m_backgroundTextures.resize(NUM_OF_BG_TEXTURES);
	if (!m_backgroundTextures[(int)Screen::HomePage].loadFromFile("home_background.png")
		|| !m_backgroundTextures[(int)Screen::LevelMenu].loadFromFile("levelmenu_background.png")
		|| !m_backgroundTextures[(int)Screen::Game].loadFromFile("game_background.png"))
	{
		std::cerr << "error loading bg textures from file\n";
	}
}

void Resources::loadLevelMenuIcons()
{
	m_levelMenuTexture.resize(2);
	if (!m_levelMenuTexture[(int)LevelState::Lock].loadFromFile("lock_level.png")
		|| !m_levelMenuTexture[(int)LevelState::Unlock].loadFromFile("unlock_level.png"))
	{
		std::cerr << "error loading player textures from file";
	}
}

void Resources::loadHomePageBtnsTexture()
{
	m_homePageBtnsTexture.resize(4);
	if (!m_homePageBtnsTexture[(int)HomeButtonType::Start].loadFromFile("start.png")
		|| !m_homePageBtnsTexture[(int)HomeButtonType::Help].loadFromFile("help.png")
		|| !m_homePageBtnsTexture[(int)HomeButtonType::Settings].loadFromFile("settings.png")
		|| !m_homePageBtnsTexture[(int)HomeButtonType::Exit].loadFromFile("exit.png"))
	{
		std::cerr << "error loading btns textures from file";
	}
}

void Resources::loadLevelActionButtonTexture()
{
	m_levelActionButtonsTexture.resize(2);
	if (!m_levelActionButtonsTexture[(int)LevelActions::Pause].loadFromFile("pause_button.png")
		|| !m_levelActionButtonsTexture[(int)LevelActions::Retry].loadFromFile("retry_button.png"))
	{
		std::cerr << "error loading btns textures from file";
	}
}

//Tali: needed??
void Resources::loadPlayers()
{
	m_players.resize(NUM_OF_PLAYERS);
	if (!m_players[(int)Player::Heavy].loadFromFile("heavy.png")
		|| !m_players[(int)Player::Light].loadFromFile("light.png")
		|| !m_players[(int)Player::Simple].loadFromFile("simple.png"))
	{
		std::cerr << "error loading player textures from file";
	}
}

void Resources::loadSettingsReturnTexture()
{
	m_settingsReturnTexture.resize(2);
	if (!m_settingsReturnTexture[1].loadFromFile("return_button.png")
		|| !m_settingsReturnTexture[0].loadFromFile("continue_button.png")
		)
		std::cerr << "error loading texture file";
}

void Resources::loadBackArrowTexture()
{
    if (!m_backArrow.loadFromFile("back_home.png"))
        std::cerr << "error loading texture file";
}

void Resources::loadSettingsHomeTexture()
{
	if (!m_settingsHomeTexture.loadFromFile("home_button.png"))
		std::cerr << "error loading texture file";
}

void Resources::loadNextLevelBtn()
{
    if (!m_nextLevelBtn.loadFromFile("next_level_btn.png"))
        std::cerr << "error loading texture file";
}

void Resources::loadRetryBtn()
{
    if (!m_retryBtn.loadFromFile("retry_btn.png"))
        std::cerr << "error loading texture file";
}

void Resources::loadMenuBtn()
{
    if (!m_menuBtn.loadFromFile("menu_btn.png"))
        std::cerr << "error loading texture file";
}

void Resources::loadPlayersFace()
{
	m_playersFace.resize(NUM_OF_PLAYERS);
	if (!m_playersFace[(int)Player::Heavy].loadFromFile("heavy_player_face.png")
		|| !m_playersFace[(int)Player::Simple].loadFromFile("simple_player_face.png")
		|| !m_playersFace[(int)Player::Light].loadFromFile("light_player_face.png"))
	{
		std::cerr << "error loading player textures from file";
	}
}

void Resources::loadObjects()
{
	m_objects.resize(NUM_OF_OBJS);

	if (!m_objects[(int)Objects::Hay].loadFromFile("hay.png") 
		|| !m_objects[(int)Objects::Rafter].loadFromFile("rafter.png")
		|| !m_objects[(int)Objects::Switch].loadFromFile("switch.png")
		|| !m_objects[(int)Objects::Billboard].loadFromFile("billboard.png"))
	{
		std::cerr << "error loading object textures from file";
	}
}

void Resources::loadGrounds()
{
	m_grounds.resize(NUM_OF_GROUNDS);

	if (!m_grounds[(int)Grounds::Left_l1].loadFromFile("left_floor_L1.png") ||
		!m_grounds[(int)Grounds::Right_l1].loadFromFile("right_floor_L1.png") ||
		!m_grounds[(int)Grounds::l2].loadFromFile("floor_L2.png") ||
		!m_grounds[(int)Grounds::Left_l3].loadFromFile("left_floor_L3.png") ||
		!m_grounds[(int)Grounds::Right_l3].loadFromFile("right_floor_L3.png")
		|| !m_grounds[(int)Grounds::Door].loadFromFile("door.png")
		|| !m_grounds[(int)Grounds::l3].loadFromFile("floor_L3.png")
		|| !m_grounds[(int)Grounds::l4].loadFromFile("floor_L4.png"))
	{
		std::cerr << "error loading ground textures from file";
	}
}

void Resources::loadSoundTexture()
{
	m_soundTextures.resize(4);

	if (!m_soundTextures[(int)SoundStatus::AudioOn].loadFromFile("audio_on.png") ||
		!m_soundTextures[(int)SoundStatus::AudioOff].loadFromFile("audio_off.png") ||
		!m_soundTextures[(int)SoundStatus::MusicOn].loadFromFile("music_on.png") ||
		!m_soundTextures[(int)SoundStatus::MusicOff].loadFromFile("music_off.png") )
	{
		std::cerr << "error loading ground textures from file";
	}
}

void Resources::loadSettingsBackground()
{
	if (!m_settingsBackground.loadFromFile("settings_bg.png"))
		std::cerr << "error loading texture file";
}

void Resources::loadWinBackground()
{
	if (!m_winBackground.loadFromFile("win_background.png"))
		std::cerr << "error loading texture file";
}

void Resources::loadPlayerSpriteSheet()
{
	m_playerSpriteSheet.resize(NUM_OF_PLAYERS);

	if (!m_playerSpriteSheet[(int)Player::Heavy].loadFromFile("heavy_spritesheet.png") ||
		!m_playerSpriteSheet[(int)Player::Simple].loadFromFile("simple_spritesheet.png") ||
		!m_playerSpriteSheet[(int)Player::Light].loadFromFile("light_spritesheet.png"))
	{
		std::cerr << "error loading player spritesheet from file";
	}
}

void Resources::loadMusic()
{
	//Noga: try vector with ptr
	if (!m_gameMusic.openFromFile("birds.wav")
		|| !m_homeMusic.openFromFile("home_music.wav"))
		std::cerr << "error loading music from file";
	
	m_gameMusic.setVolume(15);
	m_homeMusic.setVolume(15);
}

void Resources::loadAudioClick()
{
	if (!m_audioClick.loadFromFile("click.wav")) 
	{
		std::cerr << "error loading audio 'click' from file";
	}
}

void Resources::loadPlayerArrow()
{
	if (!m_playerArrow.loadFromFile("arrow.png"))
	{
		std::cerr << "error loading arrow from file";
	}
}
void Resources::loadSign()
{
	if (!m_sign.loadFromFile("destination.png"))
	{
		std::cerr << "error loading sign from file";
	}
}

