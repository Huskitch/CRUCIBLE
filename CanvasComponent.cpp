#include "CanvasComponent.h"



CRUCIBLE::CanvasComponent::CanvasComponent()
{
}


CRUCIBLE::CanvasComponent::~CanvasComponent()
{
}

void CRUCIBLE::CanvasComponent::setTexture(sf::Texture &texture)
{
	m_tileset = texture;
}
