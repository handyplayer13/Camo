#pragma once

#include "Core.h"
#include "Window.h"
#include "State.h"

namespace Camo {

	class CAMO_API Application
	{
	public:
		Application(unsigned int windowWidth, unsigned int windowHeight, const char* windowTitle);
		virtual ~Application();

		void Run();

		// Updating simulation using deltaTime, to be defined in client 
		virtual State OnUpdate(double deltaTime) = 0;
		// Rendering state to window, to be defined in client 
		virtual void OnRender(State& state, Window& window) = 0;

	protected:
		void SetDeltaTimeUpdate(double deltaTime);
		void SetDeltaTimeRender(double deltaTime);

	private:
		unsigned int m_windowWidth;
		unsigned int m_windowHeight;
		const char* m_windowTitle;

		// default values for delta times
		double m_deltaTimeUpdate = 1 / 60.0;
		double m_deltaTimeRender = 1 / 60.0;
	};

	// To be defined in client
	Application* CreateApplication();
}