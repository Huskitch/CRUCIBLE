#pragma once
#include <map>
#include <SFML/Graphics.hpp>

namespace CRUCIBLE
{
	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

	public:
		void loadTexture(const std::string& name, const std::string &filename);
		void loadFont(const std::string& name, const std::string &filename);
		sf::Texture& getTexRef(const std::string& texture);
		sf::Font& getFontRef(const std::string& font);

	private:


	private:
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::Font> fonts;
	};
}
