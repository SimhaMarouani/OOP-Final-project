#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Button.h"
#include "Window.h"
#include "Settings.h"
#include "Animation.h"
#include "Audio.h"
#include "Screen.h"

#include "Macros.h"
#include "Utilities.h"


class Window;

//HomeMenu
class HomePageScreen : public Screen
{
public:
	HomePageScreen();

	void draw(sf::RenderWindow &window);
	void processEvents(const sf::Event &event, sf::Vector2f& mouseLocation, Controller& controller);
	void handleClick(const sf::Event &event, Controller& controller);
	void initSettings(std::shared_ptr<Settings> s);
	void update(float deltaTime);  //animation
    void handleHover(const sf::Vector2f& location);

private:
	void handleMenuClick(const sf::Event& event, Controller& controller);

	void setHelpScreen();
	void initButtons();
	void drawMenu(sf::RenderWindow& window);

	sf::RectangleShape m_helpBackground;
	std::vector<Button> m_buttons;

	enum class PageStatus
	{
		Menu,
		Help,
		Settings
	};

	PageStatus m_pageStatus;
	std::shared_ptr<Settings> m_settingsView;
	
	sf::Sprite m_heavy;  //animation
	Animation m_animation;  //animation
};