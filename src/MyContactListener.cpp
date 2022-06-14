#include "MyContactListener.h"

void MyContactListener::BeginContact(b2Contact* contact) {

    //check fixture A
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    auto objA = static_cast<GameObjects*>(bodyUserDataA);
    void* fixtureUserDataA = contact->GetFixtureA()->GetUserData();

    //check fixture B
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
    auto objB = static_cast<GameObjects*>(bodyUserDataB);
    void* fixtureUserDataB = contact->GetFixtureB()->GetUserData();

    if (!objA | !objB)
        return;

    CollisionHandler::instance().processCollision(objA, objB, 
        ((int)(size_t)fixtureUserDataA == 1) ? true : false, 
        ((int)(size_t)fixtureUserDataB == 1) ? true : false, true);
}

void MyContactListener::EndContact(b2Contact* contact) {
    
    //check fixture A
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    auto objA = static_cast<GameObjects*>(bodyUserDataA);
    void* fixtureUserDataA = contact->GetFixtureA()->GetUserData();

    //check fixture B
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
    auto objB = static_cast<GameObjects*>(bodyUserDataB);
    void* fixtureUserDataB = contact->GetFixtureB()->GetUserData();

    if (!objA | !objB)
        return;
    
    CollisionHandler::instance().processCollision(objA, objB, 
        ((int)(size_t)fixtureUserDataA == 1) ? true : false,
        ((int)(size_t)fixtureUserDataB == 1) ? true : false, false);
}