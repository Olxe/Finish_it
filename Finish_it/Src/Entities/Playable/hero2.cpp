#include "hero2.h"

Hero2::Hero2(const ObjectNode* obj, const TileNode* tile, std::string texturePath, sf::Vector2f frameSize, Direction direction)
	: Heroes(obj, tile, texturePath, frameSize, direction)
{
	AddAnimation("WALK_BACK", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 12), sf::Vector2i(1, 12), sf::Vector2i(2, 12), sf::Vector2i(3, 12) });
	AddAnimation("WALK_FRONT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 13), sf::Vector2i(1, 13), sf::Vector2i(2, 13), sf::Vector2i(3, 13) });
	AddAnimation("WALK_LEFT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 14), sf::Vector2i(1, 14), sf::Vector2i(2, 14), sf::Vector2i(3, 14) });
	AddAnimation("WALK_RIGHT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 15), sf::Vector2i(1, 15), sf::Vector2i(2, 15), sf::Vector2i(3, 15) });

	AddAnimation("IDLE_BACK", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 4), sf::Vector2i(1, 4), sf::Vector2i(2, 4), sf::Vector2i(3, 4) });
	AddAnimation("IDLE_FRONT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 5), sf::Vector2i(1, 5), sf::Vector2i(2, 5), sf::Vector2i(3, 5) });
	AddAnimation("IDLE_LEFT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 6), sf::Vector2i(1, 6), sf::Vector2i(2, 6), sf::Vector2i(3, 6) });
	AddAnimation("IDLE_RIGHT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 7), sf::Vector2i(1, 7), sf::Vector2i(2, 7), sf::Vector2i(3, 7) });

	AddAnimation("ATTACK_BACK", frameSize, 0.09f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 8), sf::Vector2i(1, 8), sf::Vector2i(2, 8), sf::Vector2i(3, 8) }, false, true, 3);
	AddAnimation("ATTACK_FRONT", frameSize, 0.09f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 9), sf::Vector2i(1, 9), sf::Vector2i(2, 9), sf::Vector2i(3, 9) }, false, true, 3);
	AddAnimation("ATTACK_LEFT", frameSize, 0.09f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 10), sf::Vector2i(1, 10), sf::Vector2i(2, 10), sf::Vector2i(3, 10) }, false, true, 3);
	AddAnimation("ATTACK_RIGHT", frameSize, 0.09f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 11), sf::Vector2i(1, 11), sf::Vector2i(2, 11), sf::Vector2i(3, 11) }, false, true, 3);

	AddAnimation("HURT_BACK", frameSize, 0.3f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 3) }, false, false, 1);
	AddAnimation("HURT_FRONT", frameSize, 0.3f, std::vector<sf::Vector2i>{ sf::Vector2i(1, 3) }, false, false, 1);
	AddAnimation("HURT_LEFT", frameSize, 0.3f, std::vector<sf::Vector2i>{ sf::Vector2i(2, 3) }, false, false, 1);
	AddAnimation("HURT_RIGHT", frameSize, 0.3f, std::vector<sf::Vector2i>{sf::Vector2i(3, 3) }, false, false, 1);
	
	AddAnimation("DEAD_BACK", frameSize, 0.1f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0) }, false, true, 10);
	AddAnimation("DEAD_FRONT", frameSize, 0.1f, std::vector<sf::Vector2i>{ sf::Vector2i(3, 0), sf::Vector2i(0, 1), sf::Vector2i(1, 1) }, false, true, 10);
	AddAnimation("DEAD_LEFT", frameSize, 0.1f, std::vector<sf::Vector2i>{ sf::Vector2i(2, 1), sf::Vector2i(3, 1), sf::Vector2i(0, 2) }, false, true, 10);
	AddAnimation("DEAD_RIGHT", frameSize, 0.1f, std::vector<sf::Vector2i>{sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(3, 2) }, false, true, 10);
}

Hero2::~Hero2()
{
}