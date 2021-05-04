#include "Rectangle.h"

namespace Camo {

	float Rectangle::GetPositionX() const
	{
		return m_rectangleShape.getPosition().x;
	}

	float Rectangle::GetPositionY() const
	{
		return m_rectangleShape.getPosition().y;
	}

	void Rectangle::SetPosition(float x, float y)
	{
		m_rectangleShape.setPosition(x, y);
	}

	Drawable* Rectangle::Clone() const
	{
		return new Rectangle(*this);
	}

	sf::Drawable& Rectangle::GetInternal()
	{
		return m_rectangleShape;
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

}