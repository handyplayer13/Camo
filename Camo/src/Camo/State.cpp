#include "State.h"

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

	void State::Draw(Window& window)
	{
		window.Clear();

		for (int i = 0; i < m_drawables.size(); i++)
		{
			window.Draw(*m_drawables[i]);
		}

		window.Display();
	}

}