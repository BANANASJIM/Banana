#include <Banana.h>

class ExampleLayer : public Banana::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		BN_INFO("ExampleLayer::Update");
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
		PushOverlay(new Banana::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Banana::Application* Banana::CreateApplication()
{
	return new Sandbox();
}