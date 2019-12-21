#include "box2dworld.h"

Box2DWorld* Box2DWorld::m_instance = nullptr;

Box2DWorld::Box2DWorld()
{
    m_world = new b2World(b2Vec2(0, 0));
}

Box2DWorld::~Box2DWorld()
{
    delete m_world;
    m_world = nullptr;
}

Box2DWorld* Box2DWorld::GetInstance()
{
    if(m_instance == nullptr) m_instance = new Box2DWorld();
    
    return m_instance;
}

bool Box2DWorld::KillInstance()
{
    if(m_instance != nullptr){
        delete m_instance;
        m_instance = nullptr;
        return true;
    }
    else{
        return false;
    } 
}