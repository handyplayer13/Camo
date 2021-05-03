#include "Application.h"
#include "Window.h"

#include <SFML/Graphics.hpp>

#include <chrono>

namespace Camo {

	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const char* windowTitle)
        : m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_windowTitle(windowTitle)
	{
    
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
        Window window(m_windowWidth, m_windowHeight, m_windowTitle);

        double accumulatorUpdate = 0.0;
        double accumulatorRender = 0.0;
        auto currentTime = std::chrono::system_clock::now();

        // app runs as long as the window is open
        while (window.IsOpen())
        {
            // close window if requested
            if (window.CloseRequested())
                window.Close();

            // calculate frame time
            auto newTime = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsedTime = newTime - currentTime;
            double frameTime = elapsedTime.count();
            currentTime = newTime;

            // increment accumulators
            accumulatorUpdate += frameTime;
            accumulatorRender += frameTime;

            // update
            while (accumulatorUpdate >= m_deltaTimeUpdate)
            {
                OnUpdate(m_deltaTimeUpdate);
                accumulatorUpdate -= m_deltaTimeUpdate;
            }

            // render
            if (accumulatorRender >= m_deltaTimeRender)
            {
                State state;
                OnRender(state);
                state.Draw(window);

                accumulatorRender = 0;
            }
        }
	}

    void Application::SetDeltaTimeUpdate(double deltaTime)
    {
        m_deltaTimeUpdate = deltaTime;
    }

    void Application::SetDeltaTimeRender(double deltaTime)
    {
        m_deltaTimeRender = deltaTime;
    }

}