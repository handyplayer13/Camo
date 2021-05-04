#include "Window.h"

namespace Camo {

	Window::Window(unsigned int width, unsigned int height, const char* title)
	{
		m_renderWindow.create(sf::VideoMode(width, height), title);
	}

	bool Window::IsOpen() const
	{
		return m_renderWindow.isOpen();
	}

	bool Window::CloseRequested()
	{
		sf::Event event;
		while (m_renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return true;
		}

		return false;
	}

	void Window::Close()
	{
		m_renderWindow.close();
	}

	void Window::Clear()
	{
		m_renderWindow.clear();
	}

	void Window::Clear(uint8_t r, uint8_t g, uint8_t b)
	{
		m_renderWindow.clear(sf::Color(r, g, b));
	}

	void Window::Draw(Drawable& drawable)
	{
		m_renderWindow.draw(drawable.GetInternal());
	}

	void Window::Draw(State& state)
	{
		for (int i = 0; i < state.Size(); i++)
		{
			Draw(state.Get(i));
		}
	}

	void Window::Display()
	{
		m_renderWindow.display();
	}

}