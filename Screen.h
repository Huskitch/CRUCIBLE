#pragma once
#include "SFML/Graphics.hpp"

namespace CRUCIBLE
{
	class Screen
	{
	public:
		virtual int Run(sf::RenderWindow &App) = 0;
	};
}