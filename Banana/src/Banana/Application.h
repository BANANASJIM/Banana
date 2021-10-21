#pragma once

#include "Core.h"

#include "Window.h"
#include "Banana/LayerStack.h"
#include "Banana/Events/Event.h"
#include "Banana/Events/ApplicationEvent.h"

namespace Banana {

	class BANANA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}