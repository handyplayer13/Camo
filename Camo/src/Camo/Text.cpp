#include "Text.h"

namespace Camo {

	float Text::GetPositionX() const
	{
		return m_text.getPosition().x;
	}

	float Text::GetPositionY() const
	{
		return m_text.getPosition().y;
	}

	void Text::SetPosition(float x, float y)
	{
		m_text.setPosition(x, y);
	}

	sf::Drawable& Text::GetInternal()
	{
		return m_text;
	}

	void Text::SetFont(const char* fontFile)
	{
		m_font.loadFromFile(fontFile);
		m_text.setFont(m_font);
	}

	void Text::SetString(const char* string)
	{
		m_text.setString(string);
	}

	void Text::SetString(const std::string& string)
	{
		m_text.setString(string);
	}

	void Text::SetSize(unsigned int size)
	{
		m_text.setCharacterSize(size);
	}

	void Text::SetFillColor(uint8_t r, uint8_t g, uint8_t b)
	{
		m_text.setFillColor(sf::Color(r, g, b));
	}

}