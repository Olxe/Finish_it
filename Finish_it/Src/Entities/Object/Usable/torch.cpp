#include "torch.h"

Torch::Torch(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize)
	: Object(obj, tile, texturePath, frameSize)
{
	AddAnimation("ON", frameSize, 0.12f, std::vector<sf::Vector2i>{ sf::Vector2i(1, 0), sf::Vector2i(2, 0), sf::Vector2i(3, 0), sf::Vector2i(4, 0) });
	AddAnimation("OFF", frameSize, 1000.f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 0) });

	if (const PropertiesNode * properties = tile->GetProperties()) {
		bool isOn = properties->GetProperty("isOn").ToBool(true);
		if(isOn) LunchAnimation("ON");
		else LunchAnimation("OFF");
	}
	else LunchAnimation("ON");
}

Torch::~Torch()
{

}

void Torch::OnInteract()
{
	if (NameCurrentAnimation() == "OFF") LunchAnimation("ON");
	else if (NameCurrentAnimation() == "ON") LunchAnimation("OFF");
}