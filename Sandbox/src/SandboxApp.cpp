#include <Banana.h>

class Sandbox : public Banana::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Banana::Application* Banana::CreateApplication()
{
	return new Sandbox();
}