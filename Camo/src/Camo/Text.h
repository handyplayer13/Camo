#pragma once

#include "Core.h"
#include "Drawable.h"

#include <SFML/Graphics.hpp>

#include <string>

namespace Camo {

	class CAMO_API Text : public Drawable
	{
	public:
		virtual ~Text() = default;

		float GetPositionX() const override;
		float GetPositionY() const override;
		void SetPosition(float x, float y) override;

		void SetFont(const char* fontFile);
		void SetString(const char* string);
		void SetString(const std::string& string);
		void SetSize(unsigned int size);
		void SetFillColor(uint8_t r, uint8_t g, uint8_t b);

	private:
		// prohibit access in game
		Drawable* Clone() const override;
		sf::Drawable& GetInternal() override;

		sf::Text m_text;
		sf::Font m_font;
	};

}