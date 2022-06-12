#include "World.h"
#include "Controller.h"



World::World()
{
	m_box2dWorld = std::make_unique<b2World>(gravity);
	m_box2dWorld->SetContactListener(&contactListener);

	initSymbols();
	initPlayers();
	//createLevel(1);   //simha: i moved it to game screen constructor
}

World::~World()
{
	m_players.clear();
	m_objects.clear();
}

void World::initSymbols()
{
	m_arrow.setTexture(*Resources::instance().getPlayerArrowTexture());
	m_arrow.setOrigin(m_arrow.getGlobalBounds().width, m_arrow.getGlobalBounds().height);
	m_sign.setTexture(*Resources::instance().getSignTexture());
	m_sign.setOrigin(m_sign.getGlobalBounds().width, m_sign.getGlobalBounds().height);
}

void World::draw(sf::RenderWindow& window)
{
	window.draw(m_sign);
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

	for (int i = 0; i < m_players.size(); i++)
	{
		m_box2dWorld->Step(timeStep, velocityIterations, positionIterations);
		m_players[i]->update(deltaTime);
	}
	for (int i = 0; i < m_objects.size(); i++)
	{
		m_box2dWorld->Step(timeStep, velocityIterations, positionIterations);
		m_objects[i]->update();
	}
}

void World::moveArrow(Player active)
{
	float x = m_players[(int)active]->getPosition().x + 80;
	float y = m_players[(int)active]->getPosition().y - m_players[(int)active]->getHeight() / 2;
	m_arrow.setPosition(x, y);
}


void World::createLevel(int level)
{
	//init players positions based on level file
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

bool World::allPlayersReachedEnd()
{
	for (auto& player : m_players)
	{
		if (player->getPosition().x < m_endpoint)
			return false;
	}
	return true;
}

bool World::playerLost()
{
	for (auto& player : m_players)
	{
		if (player->getPosition().y > WINDOW_HEIGHT && player->getPosition().x < WINDOW_WIDTH)
			return true;
	}
	return false;
}

void World::initPlayers()
{
	//Players (amount and type) is constant!
	m_players.emplace_back(std::make_unique<Heavy>(getWorld()));
	m_players.emplace_back(std::make_unique<Simple>(getWorld()));
	m_players.emplace_back(std::make_unique<Light>(getWorld()));
}

void World::loadLevel(int levelNum)
{
	std::string levelName = "Level" + std::to_string(levelNum) + ".txt";
	std::ifstream levelFile;
	std::string line, objType;
	int locX, locY;
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

	getline(levelFile, line);

	//reading contents of level
	while (!levelFile.eof())
	{
		getline(levelFile, line);
		ssline.clear();
		ssline.str(line);
		ssline >> objType >> locX >> locY;

		if (isPlayer(objType)) //Tali:change to static cast
		{
			m_players[getIndPlayer(objType)]->setPosition(sf::Vector2f(locX, locY));
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
