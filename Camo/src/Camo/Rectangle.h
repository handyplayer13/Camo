#pragma once

#include "Core.h"
#include "Drawable.h"

#include <SFML/Graphics.hpp>

namespace Camo {

	class CAMO_API Rectangle : public Drawable
	{
	public:
		virtual ~Rectangle() = default;

		float GetPositionX() const override;
		float GetPositionY() const override;
		void SetPosition(float x, float y) override;

		void SetRotation(float angle);
		void SetSize(float width, float height);
		void SetFillColor(uint8_t r, uint8_t g, uint8_t b);

	private:
		// prohibit access in game
		Drawable* Clone() const override;
		sf::Drawable& GetInternal() override;

		sf::RectangleShape m_rectangleShape;
	};

}