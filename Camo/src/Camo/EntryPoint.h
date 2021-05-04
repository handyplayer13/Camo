#pragma once

#ifdef CM_PLATFORM_WINDOWS

extern Camo::Application* Camo::CreateApplication();

int main(int argc, char** argv)
{
	// initialize logging system
	Camo::Log::Init();
	CM_CORE_INFO("Log initialized");

	// create and run application
	auto app = Camo::CreateApplication();
	app->Run();
	delete app;
}

#endif