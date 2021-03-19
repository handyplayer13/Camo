#pragma once

#ifdef CM_PLATFORM_WINDOWS
	#ifdef CM_BUILD_DLL
		#define CAMO_API __declspec(dllexport)
	#else
		#define CAMO_API __declspec(dllimport)
	#endif
#else
	#error Camo only supports Windows!
#endif