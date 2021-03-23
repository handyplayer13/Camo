#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Camo {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// set a pattern for logging messages
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		// create core logger and set logging level
		s_CoreLogger = spdlog::stdout_color_mt("CAMO");
		s_CoreLogger->set_level(spdlog::level::trace);

		// create client logger and set logging level
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}