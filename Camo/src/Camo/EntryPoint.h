#pragma once

#ifdef CM_PLATFORM_WINDOWS

extern Camo::Application* Camo::CreateApplication();

int main(int argc, char** argv)
{
	Camo::Log::Init();
	CM_CORE_WARN("Initialized Log!");
	int a = 5;
	CM_INFO("Hello! Var={0}", a);

	auto app = Camo::CreateApplication();
	app->Run();
	delete app;
}

#endif