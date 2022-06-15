#include "World.h"
#include "Controller.h"



World::World()
{
	m_box2dWorld = std::make_unique<b2World>(gravity);
	m_box2dWorld->SetContactListener(&m_contactListener);

	createBorders();
	initSymbols();
	initPlayers();
}

World::~World()
{
	m_players.clear();
	m_objects.clear();
}

void World::createBorders()
{
	//Borders are constant
	m_borders.emplace_back(std::make_unique<Border>(getWorld(), sf::Vector2f(-30, WINDOW_HEIGHT / 2), 10, WINDOW_HEIGHT));
	m_borders.emplace_back(std::make_unique<Border>(getWorld(), sf::Vector2f(WINDOW_WIDTH/2,-30), WINDOW_WIDTH, 10));
	m_borders.emplace_back(std::make_unique<Border>(getWorld(), sf::Vector2f(WINDOW_WIDTH+30, WINDOW_HEIGHT / 2), 10, WINDOW_HEIGHT));
}

void World::initPlayers()
{
	//Players (amount and type) are constant
	m_players.emplace_back(std::make_unique<Heavy>(getWorld()));
	m_players.emplace_back(std::make_unique<Simple>(getWorld()));
	m_players.emplace_back(std::make_unique<Light>(getWorld()));
}
void World::initSymbols()
{
	m_arrow.setTexture(*Resources::instance().getPlayerArrowTexture());
	m_arrow.setOrigin(m_arrow.getGlobalBounds().width, m_arrow.getGlobalBounds().height);
	m_sign.setTexture(*Resources::instance().getSignTexture());
	m_sign.setOrigin(m_sign.getGlobalBounds().width, m_sign.getGlobalBounds().height);
}

void World::draw(sf::RenderWindow& window, const Player activePlayer)
{
	window.draw(m_sign);
	for (auto& object : m_objects)
	{
		object->draw(window);
	}
	for (int i = 0; i < m_players.size(); i++)
	{
		if (i != static_cast<int>(activePlayer))
		{
			m_players[i]->draw(window);
		}
	}
	m_players[static_cast<int>(activePlayer)]->draw(window);
	window.draw(m_arrow);
}

void World::moveActive(float deltaTime, const Player active)
{
	for (int i = 0; i < m_objects.size(); i++)
	{
		m_box2dWorld->Step(timeStep, velocityIterations, positionIterations);
		m_objects[i]->updateObj();
		if (auto sw = dynamic_cast<Door*>(m_objects[i].get()))
		{
			sw->updateDoorState();
		}
	}

	m_box2dWorld->Step(timeStep, velocityIterations, positionIterations);
	m_players[static_cast<int>(active)]->move(deltaTime);

	for (int i = 0; i < m_players.size(); i++)
	{
		m_box2dWorld->Step(timeStep, velocityIterations, positionIterations);
		m_players[i]->update(deltaTime);
	}
	
}

void World::moveArrow(const Player active)
{
	float x = m_players[static_cast<int>(active)]->getPosition().x + 80;
	float y = m_players[static_cast<int>(active)]->getPosition().y - m_players[static_cast<int>(active)]->getHeight() / 2;
	m_arrow.setPosition(x, y);
}


void World::createLevel(const int level)
{
	try {
		loadLevel(level);
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

bool World::allPlayersReachedEnd()const
{
	for (auto& player : m_players)
	{
		if (player->getPosition().x < m_endpoint)
			return false;
	}
	return true;
}

bool World::playerLost()const
{
	for (auto& player : m_players)
	{
		if (player->getPosition().y > WINDOW_HEIGHT && player->getPosition().x < WINDOW_WIDTH)
			return true;
	}
	return false;
}


void World::loadLevel(const int levelNum)
{
	std::string levelName = "Level" + std::to_string(levelNum) + ".txt";
	std::ifstream levelFile;
	std::string line, objType;
	float locX, locY;
	float scaleX, scaleY;
	std::stringstream ssline;

	levelFile.exceptions(std::ifstream::badbit);
	ssline.exceptions(ssline.failbit |  ssline.badbit);
	
	m_objects.clear();

	levelFile.open(levelName);
	levelFile.seekg(0);

	//reading level end point
	getline(levelFile, line);
	ssline.clear();
	ssline.str(line);
	ssline >> m_endpoint;
	
	//read sign location
	getline(levelFile, line);
	ssline.clear();
	ssline.str(line);
	ssline >> locX >> locY >> scaleX >> scaleY;
	m_sign.setPosition(sf::Vector2f(locX, locY));
	m_sign.setScale(sf::Vector2f(scaleX, scaleY));

	getline(levelFile, line); //Read line of labels in file

	//reading contents of level
	while (getline(levelFile, line))
	{
		ssline.clear();
		ssline.str(line);
		ssline >> objType >> locX >> locY;

		if (isPlayer(objType))
		{
			m_players[getIndPlayer(objType)]->setPosition(sf::Vector2f(locX, locY));
			m_players[getIndPlayer(objType)]->setFaceRight(true);
			m_players[getIndPlayer(objType)]->setDirection(Direction::None);
		}
		else //create the object
		{
			ssline >> scaleX >> scaleY;
			auto o = ObjectFactory::create(objType, sf::Vector2f(locX, locY), getWorld(), sf::Vector2f(scaleX, scaleY));
			if (o)
			{
				if (auto obj = dynamic_cast<Switch*>(o.get()))
				{
					obj->setDoor(m_objects.back().get());
				}
				m_objects.emplace_back(move(o));
			}
			else //wasnt able to create object
				throw std::invalid_argument("");
		}
		if (levelFile.eof()) break;
	}
	levelFile.close();
}

bool World::isPlayer(const std::string type)const
{
	return type == PLAYERS[0]
			|| type == PLAYERS[1]
			|| type == PLAYERS[2];
}

int World::getIndPlayer(const std::string player)const
{
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
		if (PLAYERS[i] == player)
			return i;
	return 0;
}
