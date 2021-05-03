#pragma once

#include "Core.h"
#include "Drawable.h"

#include <SFML/Graphics.hpp>

namespace Camo {

	class Window
	{
	public:
		Window(unsigned int width, unsigned int height, const char* title);
		bool IsOpen() const;
		bool CloseRequested();
		void Close();
		void Clear();
		void Draw(Drawable& drawable);
		void Display();

	private:
		sf::RenderWindow m_renderWindow;
	};

}