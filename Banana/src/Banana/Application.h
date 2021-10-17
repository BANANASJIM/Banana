#pragma once

#include "Core.h"

namespace Banana {
	
	class BANANA_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();

}

