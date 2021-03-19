#pragma once

#ifdef CM_PLATFORM_WINDOWS

extern Camo::Application* Camo::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Camo::CreateApplication();
	app->Run();
	delete app;
}

#endif