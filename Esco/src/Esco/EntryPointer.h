#pragma once
#include <stdio.h>

#ifdef ESCO_PLATFORM_WINDOWS

extern Esco::Application* Esco::CreateApplication();

int main(int argc, int** argv) {
	printf("Welcome to Esco Engine...\n");
	auto app = Esco::CreateApplication();
	app->run();
	delete app;
}

#else
#error Now, Esco only supports Windows...
#endif // ESCO_PLATFORM_WINDOWS
