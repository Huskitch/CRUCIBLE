#pragma once
#include <SFML/Graphics.hpp>

namespace CRUCIBLE
{
	class CanvasComponent : public sf::Drawable, public sf::Transformable
	{
	public:
		CanvasComponent();
		~CanvasComponent();
		void setTexture(sf::Texture &texture);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			states.transform *= getTransform();
			states.texture = &m_tileset;
			target.draw(m_vertices, states);
		}

		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
	};
}
