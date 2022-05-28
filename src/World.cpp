#include "World.h"
#include "Controller.h"

//box2d

const float timeStep = 1.0f / 60.0f;
const int32 velocityIterations = 6,
			positionIterations = 2;
const b2Vec2 gravity = b2Vec2(0.0f, 10.0f);
const sf::Vector2f initVec = sf::Vector2f(0.f, 0.f);
const int OFFSET = 37;


World::World()
	:m_box2dWorld(gravity)
{
	m_arrow.setTexture(*Resources::instance().getArrowTexture());
	m_arrow.setScale(sf::Vector2f(0.04, 0.04));
	m_arrow.setOrigin(m_arrow.getGlobalBounds().width, m_arrow.getGlobalBounds().height);
	m_arrow.setPosition(50, 50);		//Simha: i'll set the position according to the active player later


	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.f, WINDOW_HEIGHT - 150);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = m_box2dWorld.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(500.0f, 2.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);
 
	//init players positions based on level file
	try {
		loadLevel();
	}
	catch (const std::ifstream::failure& e) //catches fstream error and sstream
	{
		std::cerr << "There was an error opening level file OR reading input\n";
		exit(EXIT_FAILURE);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "There was an error opening level file\n";
		exit(EXIT_FAILURE);

	}
}

void World::draw(sf::RenderWindow& window)
{
	for (auto& movable : m_players)
	{
		movable->draw(window);
	}
	window.draw(m_arrow);
}

void World::setActiveDirection(Direction dir, Player active)
{
	m_players[(int)active]->setDirection(dir);
}

void World::moveActive(float deltaTime, Player active)
{
	
	for (int i = 0; i < m_players.size(); i++)
	{
		m_box2dWorld.Step(timeStep, velocityIterations, positionIterations);
		m_players[i]->move(deltaTime);
	}
	/*m_box2dWorld.Step(timeStep, velocityIterations, positionIterations);
	m_players[(int)active].move(deltaTime);*/
}

void World::loadLevel()
{
	std::ifstream levelFile;
	std::string line, locX, locY;
	std::stringstream ssline;

	levelFile.exceptions(std::ifstream::badbit);
	ssline.exceptions(ssline.failbit |  ssline.badbit);

	levelFile.open("Level1.txt");
	while (!levelFile.eof())
	{
		getline(levelFile, line);
		ssline.clear();
		ssline.str(line);
		ssline >> line;

		auto p = PlayerFactory::create(line);
		if (p)
		{
			ssline >> locX >> locY;

			p->setPostition(sf::Vector2f(std::stoi(locX), std::stoi(locY)));
			p->createBody(&m_box2dWorld);
			m_players.emplace_back(move(p));
		}
		else
			throw std::invalid_argument("");
	}
	levelFile.close();
}
