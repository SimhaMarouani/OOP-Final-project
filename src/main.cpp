#include <iostream>
#include "Controller.h"


int main()
{
	Controller game;
	game.run();

	return 0;
}


//
//#include <SFML/Graphics.hpp>
//#include "box2d/box2d.h"
//#include <iostream>
//
//int main()
//{
//	auto window = sf::RenderWindow(sf::VideoMode(1000, 1000), "Box2D");
//
//	// Define the gravity vector.
//	b2Vec2 gravity(0.0f, 10.0f);
//
//	// Construct a world object, which will hold and simulate the rigid bodies.
//	b2World world(gravity);
//
//	// Define the ground body.
//	b2BodyDef groundBodyDef;
//	groundBodyDef.position.Set(0.0f, 8.0f);
//
//	// Call the body factory which allocates memory for the ground body
//	// from a pool and creates the ground box shape (also from a pool).
//	// The body is also added to the world.
//	b2Body* groundBody = world.CreateBody(&groundBodyDef);
//
//	// Define the ground box shape.
//	b2PolygonShape groundBox;
//
//	// The extents are the half-widths of the box.
//	groundBox.SetAsBox(50.0f, 1.0f);
//
//	// Add the ground fixture to the ground body.
//	groundBody->CreateFixture(&groundBox, 0.0f);
//
//	// Define the dynamic body. We set its position and call the body factory.
//	b2BodyDef bodyDef;
//	bodyDef.type = b2_dynamicBody;
//	bodyDef.position.Set(4.0f, 4.0f);
//	b2Body* body = world.CreateBody(&bodyDef);
//
//	// Define another box shape for our dynamic body.
//	b2PolygonShape dynamicBox;
//	dynamicBox.SetAsBox(1.0f, 1.0f);
//
//	// Define the dynamic body fixture.
//	b2FixtureDef fixtureDef;
//	fixtureDef.shape = &dynamicBox;
//
//
//	//body->SetGravityScale(-0.1f);
//	// 
//	// Set the box density to be non-zero, so it will be dynamic.
//	fixtureDef.density = 1.0f;
//
//	// Override the default friction.
//	fixtureDef.friction = 0.3f;
//
//	// Add the shape to the body.
//	body->CreateFixture(&fixtureDef);
//
//	// Prepare for simulation. Typically we use a time step of 1/60 of a
//	// second (60Hz) and 10 iterations. This provides a high quality simulation
//	// in most game scenarios.
//	float timeStep = 1.0f / 60.0f;
//	int32 velocityIterations = 6;
//	int32 positionIterations = 2;
//
//	b2Vec2 position = body->GetPosition();
//	float angle = body->GetAngle();
//
//	auto rect = sf::RectangleShape({ 40.f, 40.f });
//	rect.setFillColor(sf::Color::Green);
//
//	//============
//	auto ground = sf::RectangleShape({ 1000.f, 20.f });
//	b2Vec2 groundPos = groundBody->GetPosition();
//	groundPos *= 100.f;
//	groundPos.y -= 160;
//
//	ground.setFillColor(sf::Color::Green);
//	ground.setPosition(groundPos.x, groundPos.y);
//
//	//============
//
//	auto worldStepCounter = 60;
//
//	window.setFramerateLimit(60);
//
//	while (window.isOpen())
//	{
//		window.clear();
//
//		if (worldStepCounter--)
//		{
//			world.Step(timeStep, velocityIterations, positionIterations);
//			position = body->GetPosition();
//			position *= 100.f;
//			angle = body->GetAngle();
//
//			rect.setPosition(position.x, position.y);
//			rect.setRotation(angle);
//
//		}
//		window.draw(rect);
//		window.draw(ground);
//		window.display();
//
//		for (auto event = sf::Event{}; window.pollEvent(event); )
//		{
//			switch (event.type)
//			{
//			case sf::Event::Closed:
//				window.close();
//				break;
//
//			case sf::Event::KeyPressed:
//				if (event.key.code == sf::Keyboard::Up)
//				{
//					body->ApplyLinearImpulse({ 0 ,-20 }, body->GetPosition(), true);
//					break;
//				}
//				if (event.key.code == sf::Keyboard::Right)
//				{
//					body->ApplyLinearImpulse({ 5 ,0 }, body->GetPosition(), true);
//					break;
//				}
//				if (event.key.code == sf::Keyboard::Left)
//				{
//					body->ApplyLinearImpulse({ -5 , 0 }, body->GetPosition(), true);
//					break;
//				}
//
//			}
//		}
//	}
//
//	return EXIT_SUCCESS;
//}