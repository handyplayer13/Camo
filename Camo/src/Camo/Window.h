#pragma once

#include "Core.h"
#include "Drawable.h"
#include "State.h"

#include <SFML/Graphics.hpp>

namespace Camo {

	class CAMO_API Window
	{
	public:
		Window(unsigned int width, unsigned int height, const char* title);
		bool IsOpen() const;
		bool CloseRequested();
		void Close();
		void Clear();
		void Clear(uint8_t r, uint8_t g, uint8_t b);
		void Draw(Drawable& drawable);
		void Draw(State& state);
		void Display();

	private:
		sf::RenderWindow m_renderWindow;
	};

}