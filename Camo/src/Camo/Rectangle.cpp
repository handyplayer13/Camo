#include "Rectangle.h"

namespace Camo {

	void Rectangle::SetPosition(float x, float y)
	{
		m_rectangleShape.setPosition(x, y);
	}

	void Rectangle::SetRotation(float angle)
	{
		m_rectangleShape.setRotation(angle);
	}

	void Rectangle::SetSize(float width, float height)
	{
		m_rectangleShape.setSize(sf::Vector2f(width, height));
	}

	void Rectangle::SetFillColor(uint8_t r, uint8_t g, uint8_t b)
	{
		m_rectangleShape.setFillColor(sf::Color(r, g, b));
	}

	sf::Drawable& Rectangle::GetInternal()
	{
		return m_rectangleShape;
	}

}