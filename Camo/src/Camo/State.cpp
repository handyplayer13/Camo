#include "State.h"

#include <cassert>

namespace Camo {

	void State::Add(const Drawable& drawable)
	{
		m_drawables.push_back(drawable.Clone());
	}

	Drawable& State::Get(int index)
	{
		return *m_drawables.at(index);
	}

	int State::Size() const
	{
		return m_drawables.size();
	}

	void State::Clear()
	{
		// free memory
		for (int i = 0; i < m_drawables.size(); i++)
		{
			delete m_drawables[i];
		}

		m_drawables.clear();
	}

	State State::Interpolate(State& currentState, State& previousState, double alpha)
	{
		assert(currentState.Size() == previousState.Size() && "Error interpolating states due to different sizes");

		State interpolatedState;

		for (int i = 0; i < currentState.Size(); i++)
		{
			const Drawable& current = currentState.Get(i);
			const Drawable& previous = previousState.Get(i);

			// interpolate position
			double interpolatedPositionX = Interpolate(current.GetPositionX(), previous.GetPositionX(), alpha);
			double interpolatedPositionY = Interpolate(current.GetPositionY(), previous.GetPositionY(), alpha);

			interpolatedState.Add(currentState.Get(i));
			interpolatedState.Get(i).SetPosition(interpolatedPositionX, interpolatedPositionY);
		}

		return interpolatedState;
	}

	float State::Interpolate(float current, float previous, double alpha)
	{
		return current * alpha + previous * (1.0 - alpha);
	}

}