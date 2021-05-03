#pragma once

#include "Core.h"
#include "Drawable.h"
#include "Window.h"

#include <vector>

namespace Camo {
	
	class State
	{
	public:
		CAMO_API void Add(Drawable& drawable);
		CAMO_API Drawable& Get(int index);
		CAMO_API int Size() const;
		void Draw(Window& window);

	private:
		std::vector<Drawable*> m_drawables;
	};

}