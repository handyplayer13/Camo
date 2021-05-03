#include "State.h"

#include <cassert>

namespace Camo {

	void State::Add(Drawable& drawable)
	{
		m_drawables.push_back(&drawable);
	}

	Drawable& State::Get(int index)
	{
		return *m_drawables.at(index);
	}

	int State::Size() const
	{
		return m_drawables.size();
	}

	State State::Interpolate(State& currentState, State& previousState, double alpha)
	{
		assert(currentState.Size() == previousState.Size() && "Error interpolating states due to different sizes");

		State interpolatedState = currentState;

		for (int i = 0; i < currentState.Size(); i++)
		{
			double positionX = currentState.Get(i).GetPositionX() * alpha + previousState.Get(i).GetPositionX() * (1.0 - alpha);
			double positionY = currentState.Get(i).GetPositionY() * alpha + previousState.Get(i).GetPositionY() * (1.0 - alpha);

			interpolatedState.Get(i).SetPosition(positionX, positionY);
		}

		return interpolatedState;
	}

}