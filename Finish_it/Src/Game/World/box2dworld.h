#ifndef __Box2DWorld__
#define __Box2DWorld__

#include <Box2D/Box2D.h>

class Box2DWorld
{
private:
    Box2DWorld();
    ~Box2DWorld();

public:
    static Box2DWorld* GetInstance();
    static bool KillInstance();

    b2World* GetWorld() const { return m_world; }

private:
    static Box2DWorld* m_instance;
    b2World * m_world;

};

#endif