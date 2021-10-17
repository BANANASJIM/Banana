#pragma once

#ifdef BN_PlATFORM_WINDOWS

extern Banana::Application* Banana::CreateApplication();

int main(int argc,char** argv)
{
	Banana::Log::Init();
	BN_CORE_WARN("Initialized Log!");
	int a = 5;
	BN_CORE_INFO("Hello! Var={0}",a);


	auto app = Banana::CreateApplication();
	app->Run();
	delete app;

}

#endif 