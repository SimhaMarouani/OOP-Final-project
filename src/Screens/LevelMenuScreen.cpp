#include "Screens/LevelMenuScreen.h"
#include "Controller.h" // Noga: I dont know why but if I put this line to header file bad things happened

LevelMenuScreen::LevelMenuScreen()
	: m_levels(10 , Button(sf::Vector2f(150.f, 150.f)))
{
	//TODO: move to const and init function
	float size = 150.f;
	float margin = 80.f;
	int num_of_cols = 5;
	int num_of_rows = floor(int(m_levels.size()) / num_of_cols);
	auto offset_x = (WINDOW_WIDTH - (size + margin) * num_of_cols) / 2;
	auto offset_y = (WINDOW_HEIGHT - (size + margin)*  num_of_rows) / 2;

	for (int i = 0; i < m_levels.size(); i++)
	{
		auto y = floor(i / num_of_cols);
		auto x = i % num_of_cols;

		std::cout << (size + margin) * float(x) << " , " << (size + margin) * float(y) << std::endl;
		m_levels[i].setPosition({ offset_x + (size + margin) * float(x), offset_y + (size + margin) * float(y) });
		m_levels[i].setColor(sf::Color(30, 30 , 30));
	}
}

void LevelMenuScreen::draw(sf::RenderWindow& window)
{
	for (auto& l : m_levels)
	{
		l.draw(window);
	}
}

void LevelMenuScreen::handleClick(sf::Event event, Controller& controller)
{
	for (int i = 0; i < m_levels.size(); i++)
	{
		if (m_levels[i].isContain(event))
		{
			controller.startGame(Page::Game, i+1);
		}
	}
}
