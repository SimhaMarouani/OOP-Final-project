#include "World.h"
#include "Controller.h"

//box2d

const float timeStep = 1.0f / 60.0f;
const int32 velocityIterations = 6,
			positionIterations = 2;
const b2Vec2 gravity = b2Vec2(0.0f, 10.0f);
const sf::Vector2f initVec = sf::Vector2f(0.f, 0.f);
const int OFFSET = 37;

//int numFootContacts;

World::World()
{

	m_box2dWorld = new b2World(gravity);

	//// Define the ground body.
	//b2BodyDef groundBodyDef;
	//groundBodyDef.type = b2_staticBody;
	//groundBodyDef.position.Set(0.f, WINDOW_HEIGHT - 150);
	// 
	//// Call the body factory which allocates memory for the ground body
	//// from a pool and creates the ground box shape (also from a pool).
	//// The body is also added to the world.
	////b2Body* groundBody = m_box2dWorld.CreateBody(&groundBodyDef);
	//groundBody = m_box2dWorld->CreateBody(&groundBodyDef);

	//// Define the ground box shape.
	//b2PolygonShape groundBox;

	//// The extents are the half-widths of the box.
	//groundBox.SetAsBox(500.0f, 2.0f);

	//// Add the ground fixture to the ground body.
	//groundBody->CreateFixture(&groundBox, 0.0f);
	//
	initArrow();
	initPlayers();
	createLevel(1);
	
}

void World::initArrow()
{
	m_arrow.setTexture(*Resources::instance().getPlayerArrowTexture());
	m_arrow.setScale(sf::Vector2f(0.04, 0.04));
	m_arrow.setOrigin(m_arrow.getGlobalBounds().width, m_arrow.getGlobalBounds().height);
}

void World::draw(sf::RenderWindow& window)
{
	for (auto& object : m_objects)
	{
		object->draw(window);
	}
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
	
	m_box2dWorld->Step(timeStep, velocityIterations, positionIterations);
	m_players[(int)active]->move(deltaTime);

	//for (int i = 0; i < m_players.size(); i++)
	//{
	//	m_box2dWorld->Step(timeStep, velocityIterations, positionIterations);
	//	m_players[i]->move(deltaTime);
	//}
	for (int i = 0; i < m_objects.size(); i++)
	{
		m_box2dWorld->Step(timeStep, velocityIterations, positionIterations);
		m_objects[i]->update();
	}
}

void World::moveArrow(Player active)
{
	float x = m_players[(int)active]->getPosition().x;
	float y = m_players[(int)active]->getPosition().y - m_players[(int)active]->getHeight();
	m_arrow.setPosition(x, y);
}


void World::createLevel(int level)
{
	//init players positions based on level file
	//initPlayers();
	try {
		loadLevel(level); //Tali: change to const
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


void World::initPlayers()
{
	//Players (amount and type) is constant!
	m_players.emplace_back(std::make_unique<Heavy>(m_box2dWorld));
	m_players.emplace_back(std::make_unique<Simple>(m_box2dWorld));
	m_players.emplace_back(std::make_unique<Light>(m_box2dWorld));
}

void World::loadLevel(int levelNum)
{
	std::string levelName = "Level" + std::to_string(levelNum) + ".txt";
	std::ifstream levelFile;
	std::string line, objType;
	int locX, locY;
	std::stringstream ssline;

	levelFile.exceptions(std::ifstream::badbit);
	ssline.exceptions(ssline.failbit |  ssline.badbit);
	m_objects.clear();

	levelFile.open(levelName);
	while (!levelFile.eof())
	{
		getline(levelFile, line);
		ssline.clear();
		ssline.str(line);
		ssline >> objType >> locX >> locY;

		if (isPlayer(objType))
		{
			m_players[getIndPlayer(objType)]->setPosition(sf::Vector2f(locX, locY));
		}
		else //create the object and then set location
		{
			auto o = ObjectFactory::create(objType, sf::Vector2f(locX, locY), m_box2dWorld);
			if (o)
			{
				m_objects.emplace_back(move(o));
			}
			else //wasnt able to create object
				throw std::invalid_argument("");
		}
	}
	levelFile.close();
}

bool World::isPlayer(std::string type)const
{
	//Tali: change to more generic //Noga: we can change this 'if' to .find() or save it as a pair / map i think
	return type == PLAYERS[0]
			|| type == PLAYERS[1]
			|| type == PLAYERS[2];
}

int World::getIndPlayer(std::string player)const //might not need in future
{
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
		if (PLAYERS[i] == player)
			return i;
	return 0; //Tali: maybe change to -1 or exception?
}
