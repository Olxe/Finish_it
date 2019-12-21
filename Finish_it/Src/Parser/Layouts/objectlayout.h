#ifndef __OBJECTLAYOUT__
#define __OBJECTLAYOUT__

#include "layout.h"
#include "../Nodes/objectgroupnode.h"
#include "../Nodes/tilenode.h"
#include "../../Game/Window/settings.h"
#include "../../Entities/Object/physicalshape.h"

#include "../../Entities/Playable/hero1.h"
#include "../../Entities/Playable/hero2.h"

#include "../../Entities/Object/Collectable/key.h"

#include "../../Entities/Object/Actionable/irondoor.h"
#include "../../Entities/Object/Actionable/piketrap.h"
#include "../../Entities/Object/Actionable/pressureplate.h"

#include "../../Entities/Object/Usable/torch.h"
#include "../../Entities/Object/Usable/stair.h"
#include "../../Entities/Object/Usable/lever.h"
#include "../../Entities/Object/Usable/wooddoor.h"
#include "../../Entities/Object/Usable/chest.h"

class ObjectLayout: public Layout
{
public:
    ObjectLayout();
    ~ObjectLayout();

	void Load(const ObjectGroupNode* objGrp, const std::vector< TileNode* >& tiles, const std::string& directory);
	void Update(const sf::Vector2f& mousePositionconst, const sf::Vector2f& positionPlayer, const float& deltaTime);
    void Draw(sf::RenderWindow& window, const sf::Vector2f& positionPlayer);

	std::shared_ptr<Heroes> GetPtrOnHero(const std::string& typeHero);
	std::vector< std::shared_ptr<PhysicalEntity> > Entities() const { return m_entities; }

	const std::vector< PhysicalShape* >& Shapes() const { return m_shapes; }

private:
    std::vector< std::shared_ptr<PhysicalEntity> > m_entities;
	std::vector< PhysicalShape* > m_shapes;

};

#endif