#include "Canvas.h"

Canvas::Canvas()
{
	container.setSize(sf::Vector2f(400, 300));
	container.setFillColor(sf::Color(100, 100, 100, 100));
}

Canvas::~Canvas()
{
}

void Canvas::Draw(sf::RenderWindow* renderWindow)
{
	
}

void Canvas::DrawShape(sf::RenderWindow *renderWindow)
{
	renderWindow->draw(container);
}

void Canvas::Resize(sf::Vector2f size)
{
	container.setSize(size);
}

void Canvas::ResizeRelative(sf::Vector2f size)
{
	// TODO Add implementation
}

void Canvas::SetPosition(sf::Vector2f position)
{
	container.setPosition(position);
}


