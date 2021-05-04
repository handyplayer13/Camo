#pragma once

#include "Core.h"
#include "Drawable.h"

#include <SFML/Graphics.hpp>

namespace Camo {

	class CAMO_API Rectangle : public Drawable
	{
	public:
		float GetPositionX() const override;
		float GetPositionY() const override;
		void SetPosition(float x, float y) override;

		void SetRotation(float angle);
		void SetSize(float width, float height);
		void SetFillColor(uint8_t r, uint8_t g, uint8_t b);

	private:
		Drawable* Clone() const override;
		sf::Drawable& GetInternal() override; // prohibit access in game

		sf::RectangleShape m_rectangleShape;
	};

}