#pragma once

#include "Core.h"

#include <SFML/Graphics.hpp>

namespace Camo {

	class Drawable
	{
	public:
		virtual float GetPositionX() const = 0;
		virtual float GetPositionY() const = 0;
		virtual void SetPosition(float x, float y) = 0;

		virtual const sf::Drawable& GetInternal() = 0;
	};

}