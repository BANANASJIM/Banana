#pragma once

#include "Core.h"

#include "Window.h"
#include "Banana/LayerStack.h"
#include "Banana/Events/Event.h"
#include "Banana/Events/ApplicationEvent.h"
#include "Banana/ImGui/ImGuiLayer.h"

#include "Banana/Renderer/Shader.h"

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

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	private:
		static Application* s_Instance;
		std::unique_ptr<Shader> m_Shader;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}