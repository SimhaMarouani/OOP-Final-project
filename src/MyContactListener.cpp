#include "MyContactListener.h"

void MyContactListener::BeginContact(b2Contact* contact) {

    //check if fixture A was the foot sensor
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    auto objA = static_cast<GameObjects*>(bodyUserDataA);
    void* fixtureUserDataA = contact->GetFixtureA()->GetUserData();

    //check if fixture B was the foot sensor
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
    auto objB = static_cast<GameObjects*>(bodyUserDataB);
    void* fixtureUserDataB = contact->GetFixtureB()->GetUserData();

    if (!objA | !objB)
        return;
    if ((int)fixtureUserDataA == 1)
    {
        std::cout << "fixture a is foot\n";
    }
    if ((int)fixtureUserDataB == 1)
    {
        std::cout << "fixture b is foot\n";
    }
    CollisionHandler::instance().processCollision(objA, objB, 
        ((int)fixtureUserDataA == 1) ? true : false, 
        ((int)fixtureUserDataB == 1) ? true : false);
}

void MyContactListener::EndContact(b2Contact* contact) {


}