#include <Camo.h>

#include <string>
#include <cmath>

class Game : public Camo::Application
{
public:
	Game(unsigned int windowWidth, unsigned int windowHeight, const char* windowTitle)
		: Application(windowWidth, windowHeight, windowTitle)
	{
		// set delta times
		SetDeltaTimeUpdate(1 / 10.0);
		SetDeltaTimeRender(1 / 60.0);

		// initialize rectangle
		m_rectangle.SetPosition(350, 275);
		m_rectangle.SetSize(100, 50);
		m_rectangle.SetFillColor(255, 255, 255);

		// initialize texts
		m_frameTimeUpdateText.SetFont("fonts/JetBrainsMono.ttf");
		m_frameTimeUpdateText.SetPosition(20, 20);
		m_frameTimeUpdateText.SetSize(25);

		m_frameTimeRenderText.SetFont("fonts/JetBrainsMono.ttf");
		m_frameTimeRenderText.SetPosition(20, 50);
		m_frameTimeRenderText.SetSize(25);

		CM_INFO("Game initialized");
	}

	~Game()
	{
		
	}

	void OnUpdate(double deltaTime)
	{
		// debug update fps
		auto newUpdateTime = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsedUpdateTime = newUpdateTime - m_lastUpdateTime;
		double actualUpdateFrameTime = elapsedUpdateTime.count();
		m_lastUpdateTime = newUpdateTime;
		m_frameTimeUpdateText.SetString("Update FPS: " + std::to_string(1 / actualUpdateFrameTime));

		// move rectangle
		double offsetX = std::sin(m_counter) * 350;
		m_rectangle.SetPosition(350 + offsetX, 275);
		m_counter += 2 * deltaTime;
	}

	void OnRender(Camo::State& state)
	{
		// debug render fps
		auto newRenderTime = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsedRenderTime = newRenderTime - m_lastRenderTime;
		double actualRenderFrameTime = elapsedRenderTime.count();
		m_lastRenderTime = newRenderTime;
		m_frameTimeRenderText.SetString("Render FPS: " + std::to_string(1 / actualRenderFrameTime));

		// adding drawables to the state makes them being rendered
		state.Add(m_frameTimeUpdateText);
		state.Add(m_frameTimeRenderText);
		state.Add(m_rectangle);
	}

private:
	double m_counter = 0;
	Camo::Rectangle m_rectangle;
	Camo::Text m_frameTimeUpdateText;
	Camo::Text m_frameTimeRenderText;
	std::chrono::system_clock::time_point m_lastUpdateTime;
	std::chrono::system_clock::time_point m_lastRenderTime;
};

Camo::Application* Camo::CreateApplication()
{
	//CM_TRACE("Trace demo logging");
	//CM_INFO("Info demo logging");
	//CM_WARN("Warn demo logging");
	//CM_ERROR("Error demo logging");
	//CM_CRITICAL("Critical demo logging");
	
	return new Game(800, 600, "My Game | Camo");
}