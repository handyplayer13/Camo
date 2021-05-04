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

        State previousState;
        State currentState;

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
                previousState.Clear();
                previousState = currentState;

                currentState = OnUpdate(m_deltaTimeUpdate);

                accumulatorUpdate -= m_deltaTimeUpdate;
            }

            // in the first frame the previous state might not be initialized
            if (previousState.Size() == 0) previousState = currentState;

            // render
            if (accumulatorRender >= m_deltaTimeRender)
            {
                const double alpha = accumulatorUpdate / m_deltaTimeUpdate;
                State state = State::Interpolate(currentState, previousState, alpha);
                OnRender(state, window);
                state.Clear();

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