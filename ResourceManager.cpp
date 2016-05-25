#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::loadTexture(const std::string& name, const std::string& filename)
{
	sf::Texture tex;
	tex.loadFromFile(filename);

	textures[name] = tex;
}

sf::Texture& ResourceManager::getRef(const std::string& texture)
{
	return textures.at(texture);
}


