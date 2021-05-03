#pragma once

#include "Core.h"
#include "Drawable.h"

#include <vector>

namespace Camo {
	
	class State
	{
	public:
		CAMO_API void Add(Drawable& drawable);
		CAMO_API Drawable& Get(int index);
		CAMO_API int Size() const;

		static State Interpolate(State& currentState, State& previousState, double alpha);

	private:
		std::vector<Drawable*> m_drawables;
	};

}