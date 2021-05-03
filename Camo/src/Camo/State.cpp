#include "State.h"
#include "Log.h"

#include <cassert>

namespace Camo {

	State& State::operator=(const State& other)
	{
		for (int i = 0; i < m_drawables.size(); i++)
		{
			delete m_drawables[i];
		}

		//CM_CORE_TRACE("COPY ASSIGNMENT OPERATOR");
		m_drawables.clear();

		for (int i = 0; i < other.Size(); i++)
		{
			m_drawables.push_back(other.m_drawables[i]->Clone());
		}

		return *this;
	}

	void State::Add(Drawable& drawable)
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

	State State::Interpolate(State& currentState, State& previousState, double alpha)
	{
		assert(currentState.Size() == previousState.Size() && "Error interpolating states due to different sizes");

		State interpolatedState = currentState;

		for (int i = 0; i < currentState.Size(); i++)
		{
			double positionX = currentState.Get(i).GetPositionX() * alpha + previousState.Get(i).GetPositionX() * (1.0 - alpha);

			//CM_CORE_TRACE(currentState.Get(i).GetPositionX());
			//CM_CORE_TRACE(previousState.Get(i).GetPositionX());
			//CM_CORE_TRACE(positionX);
			//CM_CORE_TRACE("");

			double positionY = currentState.Get(i).GetPositionY() * alpha + previousState.Get(i).GetPositionY() * (1.0 - alpha);

			interpolatedState.Get(i).SetPosition(positionX, positionY);
		}

		return interpolatedState;
	}

}