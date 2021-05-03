#pragma once

#include "Core.h"
#include "Drawable.h"

#include <SFML/Graphics.hpp>

#include <string>

namespace Camo {

	class CAMO_API Text : public Drawable
	{
	public:
		void SetFont(const char* fontFile);
		void SetString(const char* string);
		void SetString(const std::string& string);
		void SetPosition(float x, float y);
		void SetSize(unsigned int size);
		void SetFillColor(uint8_t r, uint8_t g, uint8_t b);

		sf::Drawable& GetInternal() override;

	private:
		sf::Text m_text;
		sf::Font m_font;
	};

}