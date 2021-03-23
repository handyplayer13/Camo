#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Camo {

	class CAMO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define CM_CORE_TRACE(...)    ::Camo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CM_CORE_INFO(...)     ::Camo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CM_CORE_WARN(...)     ::Camo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CM_CORE_ERROR(...)    ::Camo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CM_CORE_CRITICAL(...) ::Camo::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define CM_TRACE(...)         ::Camo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CM_INFO(...)          ::Camo::Log::GetClientLogger()->info(__VA_ARGS__)
#define CM_WARN(...)          ::Camo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CM_ERROR(...)         ::Camo::Log::GetClientLogger()->error(__VA_ARGS__)
#define CM_CRITICAL(...)      ::Camo::Log::GetClientLogger()->critical(__VA_ARGS__)