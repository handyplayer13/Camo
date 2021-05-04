#pragma once

#include "Core.h"

namespace Camo {

	class CAMO_API Input
	{
	public:
		// keyboard
		static bool IsWKeyPressed();
		static bool IsAKeyPressed();
		static bool IsSKeyPressed();
		static bool IsDKeyPressed();
		static bool IsArrowUpKeyPressed();
		static bool IsArrowLeftKeyPressed();
		static bool IsArrowDownKeyPressed();
		static bool IsArrowRightKeyPressed();

		// mouse
		static bool IsLeftMouseButtonPressed();
		static bool IsMiddleMouseButtonPressed();
		static bool IsRightMouseButtonPressed();
		static int GetMousePositionX();
		static int GetMousePositionY();
	};

}