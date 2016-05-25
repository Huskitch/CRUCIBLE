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

void CRUCIBLE::ResourceManager::loadFont(const std::string& name, const std::string& filename)
{
	sf::Font font;
	font.loadFromFile(filename);

	fonts[name] = font;
}

sf::Texture& CRUCIBLE::ResourceManager::getTexRef(const std::string& texture)
{
	return textures.at(texture);
}

sf::Font& CRUCIBLE::ResourceManager::getFontRef(const std::string& font)
{
	return fonts.at(font);
}

