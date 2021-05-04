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
		SetDeltaTimeUpdate(1 / 30.0);
		SetDeltaTimeRender(1 / 144.0);

		// initialize rectangle
		m_rectangle.SetPosition(350, 275);
		m_rectangle.SetSize(100, 50);
		m_rectangle.SetFillColor(255, 255, 255);

		// initialize texts
		m_frameTimeUpdateText.SetFont("fonts/JetBrainsMono.ttf");
		m_frameTimeUpdateText.SetPosition(20, 20);
		m_frameTimeUpdateText.SetFillColor(205, 205, 205);
		m_frameTimeUpdateText.SetSize(25);

		m_frameTimeRenderText.SetFont("fonts/JetBrainsMono.ttf");
		m_frameTimeRenderText.SetPosition(20, 50);
		m_frameTimeRenderText.SetFillColor(205, 205, 205);
		m_frameTimeRenderText.SetSize(25);

		m_controlsText.SetFont("fonts/JetBrainsMono.ttf");
		m_controlsText.SetString("W/Up   - Move Up\nS/Down - Move Down");
		m_controlsText.SetPosition(windowWidth - 200, 20);
		m_controlsText.SetFillColor(205, 205, 205);
		m_controlsText.SetSize(15);

		CM_INFO("Game initialized");
	}

	~Game()
	{
		
	}

	Camo::State OnUpdate(double deltaTime)
	{
		// debug update fps
		m_frameTimeUpdateText.SetString("Update FPS: " + std::to_string(calculateFPS(m_lastUpdateTime)));

		// move rectangle horizontally with sinus
		m_rectangle.SetPosition(350 + std::sin(m_counter) * 350, m_rectangle.GetPositionY());
		m_counter += 2 * deltaTime;

		// move rectangle vertically with input
		if (Camo::Input::IsWKeyPressed() || Camo::Input::IsArrowUpKeyPressed()) m_rectangle.Move(0, -200 * deltaTime);
		if (Camo::Input::IsSKeyPressed() || Camo::Input::IsArrowDownKeyPressed()) m_rectangle.Move(0, 200 * deltaTime);

		// check bounds
		if (m_rectangle.GetPositionY() < 0) m_rectangle.SetPosition(m_rectangle.GetPositionX(), 0);
		if (m_rectangle.GetPositionY() > m_windowHeight - 50) m_rectangle.SetPosition(m_rectangle.GetPositionX(), m_windowHeight - 50);
		
		// add drawables to the state
		Camo::State state;
		state.Add(m_rectangle);
		state.Add(m_frameTimeUpdateText);
		state.Add(m_frameTimeRenderText);
		state.Add(m_controlsText);

		return state;
	}

	void OnRender(Camo::State& state, Camo::Window& window)
	{
		// debug render fps
		m_frameTimeRenderText.SetString("Render FPS: " + std::to_string(calculateFPS(m_lastRenderTime)));

		// render state
		window.Clear(50, 50, 50);
		window.Draw(state);
		window.Display();
	}

private:
	int calculateFPS(std::chrono::system_clock::time_point& lastTime)
	{
		auto newTime = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsedTime = newTime - lastTime;
		double actualFrameTime = elapsedTime.count();
		lastTime = newTime;
		return std::round(1 / actualFrameTime);
	}

	double m_counter = 0;
	Camo::Rectangle m_rectangle;
	Camo::Text m_frameTimeUpdateText;
	Camo::Text m_frameTimeRenderText;
	Camo::Text m_controlsText;
	std::chrono::system_clock::time_point m_lastUpdateTime;
	std::chrono::system_clock::time_point m_lastRenderTime;
};

Camo::Application* Camo::CreateApplication()
{
	return new Game(800, 600, "My Game | Camo");
}