#ifndef __ENTITY__
#define __ENTITY__

#include <math.h>

#include "../Animations/animationmanager.h"
#include "../Statistics/stats.h"
#include "../../Parser/Nodes/objectnode.h"

class Entity: public AnimationManager, public Stats
{
public:
    Entity(int gid, std::string name, std::string type);
    virtual ~Entity();

	void InitEntity(std::string texturePath, sf::Vector2f frameSize, sf::Vector2i posFrame, sf::Vector2f position, float rotation);

	int GetGid() const;
    std::string Name() const { return m_name; }
	std::string Type() const { return m_type; }

    virtual void KillEntity();
    virtual float EarnLife(const float& amount);
	virtual void OnDammageTaken(const float& amount);

private:
    int m_gid;
    std::string m_name;
	std::string m_type;

};

#endif