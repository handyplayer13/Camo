#pragma once

#ifdef CM_PLATFORM_WINDOWS

extern Camo::Application* Camo::CreateApplication();

int main(int argc, char** argv)
{
	// initialize logging system
	Camo::Log::Init();
	//CM_CORE_TRACE("Log initialized");
	CM_CORE_INFO("Log initialized");
	//CM_CORE_WARN("Log initialized");
	//CM_CORE_ERROR("Log initialized");
	//CM_CORE_CRITICAL("Log initialized");

	// create and run application
	auto app = Camo::CreateApplication();
	app->Run();
	delete app;
}

#endif