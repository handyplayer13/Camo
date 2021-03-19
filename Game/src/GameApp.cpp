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
	return new Game();
}