#pragma once
#include <SFML/Graphics.hpp>

namespace CRUCIBLE
{
	class Debug
	{
	public:
		Debug();
		~Debug();

		sf::Font font;
		sf::Clock fpsClock;

		sf::Text DrawText(std::string string, sf::Vector2f position, uint32_t scale, sf::Color color);
		void Draw(sf::RenderWindow *window);
		float GetFPS(const sf::Time& time);
	};
}
