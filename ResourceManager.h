#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>

namespace CRUCIBLE
{
	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

	public:
		void loadTexture(const std::string& name, const std::string &filename);
		sf::Texture& getRef(const std::string& texture);

	private:


	private:
		std::map<std::string, sf::Texture> textures;
	};
}
