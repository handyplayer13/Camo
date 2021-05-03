#pragma once

#include "Core.h"
#include "Drawable.h"

#include <SFML/Graphics.hpp>

namespace Camo {

	class CAMO_API Rectangle : public Drawable
	{
	public:
		void SetPosition(float x, float y);
		void SetRotation(float angle);
		void SetSize(float width, float height);
		void SetFillColor(uint8_t r, uint8_t g, uint8_t b);

		sf::Drawable& GetInternal() override;

	private:
		sf::RectangleShape m_rectangleShape;
	};

}