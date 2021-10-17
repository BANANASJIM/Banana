#pragma once

#ifdef BN_PlATFORM_WINDOWS

extern Banana::Application* Banana::CreateApplication();

int main(int argc,char** argv)
{
	printf("Banana");
	auto app = Banana::CreateApplication();
	app->Run();
	delete app;

}

#endif 