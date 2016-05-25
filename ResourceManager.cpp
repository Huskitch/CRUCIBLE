#include "ResourceManager.h"

CRUCIBLE::ResourceManager::ResourceManager()
{
}

CRUCIBLE::ResourceManager::~ResourceManager()
{
}

void CRUCIBLE::ResourceManager::loadTexture(const std::string& name, const std::string& filename)
{
	sf::Texture tex;
	tex.loadFromFile(filename);

	textures[name] = tex;
}

sf::Texture& CRUCIBLE::ResourceManager::getRef(const std::string& texture)
{
	return textures.at(texture);
}


