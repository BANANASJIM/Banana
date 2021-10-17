#include "Application.h"

#include "Banana/Events/ApplicationEvent.h"
#include "Log.h"

namespace Banana {

	Application::Application()
	{}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			BN_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			BN_TRACE(e);
		}
		while (true);
	}

}