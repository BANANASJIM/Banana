#include <Banana.h>
#include "imgui/imgui.h"

class ExampleLayer : public Banana::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//BN_INFO("ExampleLayer::Update");
		if (Banana::Input::IsKeyPressed(BN_KEY_TAB))
			BN_TRACE("TAB key is pressed!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}


	void OnEvent(Banana::Event& event) override
	{
		BN_TRACE("{0}", event);
	}

};
class Sandbox : public Banana::Application
{
public:
	Sandbox()

	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Banana::Application* Banana::CreateApplication()
{
	return new Sandbox();
}