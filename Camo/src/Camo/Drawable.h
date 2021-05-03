#pragma once

#include "Core.h"

#include <SFML/Graphics.hpp>

namespace Camo {

	class CAMO_API Drawable
	{
	public:
		virtual const sf::Drawable& GetInternal() = 0;
	};

}