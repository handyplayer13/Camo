#pragma once

#include "Core.h"
#include "Drawable.h"

#include <vector>

namespace Camo {
	
	class State
	{
	public:
		CAMO_API void Add(const Drawable& drawable);
		CAMO_API Drawable& Get(int index);
		CAMO_API int Size() const;
		void Clear();
		static State Interpolate(State& currentState, State& previousState, double alpha);

	private:
		static float Interpolate(float current, float previous, double alpha);

		std::vector<Drawable*> m_drawables;
	};

}