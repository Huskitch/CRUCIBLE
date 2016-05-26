#include "Canvas.h"

CRUCIBLE::Canvas::Canvas()
{
	container.setSize(sf::Vector2f(400, 300));
	container.setFillColor(sf::Color(100, 100, 100, 100));
}

CRUCIBLE::Canvas::~Canvas()
{
}

void CRUCIBLE::Canvas::Draw(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(components[0]);
	for(CanvasComponent e : components)
	{
		e.setPosition(container.getPosition() + e.getPosition());

	}
}

void CRUCIBLE::Canvas::AddComponent(CanvasComponent &drawableComponent)
{
	components.push_back(drawableComponent);
}


void CRUCIBLE::Canvas::DrawShape(sf::RenderWindow *renderWindow)
{
	renderWindow->draw(container);
}

void CRUCIBLE::Canvas::Resize(sf::Vector2f size)
{
	container.setSize(size);
}

void CRUCIBLE::Canvas::ResizeRelative(sf::Vector2f size)
{
	// TODO Add implementation
}

void CRUCIBLE::Canvas::SetPosition(sf::Vector2f position)
{
	container.setPosition(position);
}


