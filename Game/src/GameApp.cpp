#include <Camo.h>

class Game : public Camo::Application
{
public:
	Game()
	{

	}

	~Game()
	{

	}
};

Camo::Application* Camo::CreateApplication()
{
	CM_TRACE("Trace demo logging");
	CM_INFO("Info demo logging");
	CM_WARN("Warn demo logging");
	CM_ERROR("Error demo logging");
	CM_CRITICAL("Critical demo logging");
	
	return new Game();
}