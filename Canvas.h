#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace CRUCIBLE
{
	class Canvas
	{
	public:
		Canvas();
		~Canvas();

		void Draw(sf::RenderWindow *renderWindow);
		void DrawShape(sf::RenderWindow *renderWindow);
		void Resize(sf::Vector2f size);
		void ResizeRelative(sf::Vector2f size);
		void SetPosition(sf::Vector2f position);

	private:
		sf::RectangleShape container;
	};
}
