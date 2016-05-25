#include "Debug.h"
#include "FPS.h"

Debug::Debug()
{
	font.loadFromFile("resource/myriad-pro-bold.ttf");
}

Debug::~Debug()
{
}

sf::Text Debug::DrawText(std::string string, sf::Vector2f position, uint32_t scale, sf::Color color)
{
	sf::Text text(string, font);
	text.setPosition(position);
	text.setColor(color);
	text.setCharacterSize(scale);
	return text;
}

void Debug::Draw(sf::RenderWindow *window)
{
	float fps = GetFPS(fpsClock.restart());

	window->draw(DrawText("CRUCIBLE", sf::Vector2f(10, 5), 40, sf::Color::White));
	window->draw(DrawText("EXPERIMENTAL", sf::Vector2f(190, 5), 40, sf::Color(240, 126, 24)));
	window->draw(DrawText("FPS: " + std::to_string(fps), sf::Vector2f(15, 50), 20, sf::Color::White));
}

float Debug::GetFPS(const sf::Time& time)
{
	return (1000000.0f / time.asMicroseconds());
}

