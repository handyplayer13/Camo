#pragma once

#include "Core.h"

namespace Camo {

	class CAMO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}