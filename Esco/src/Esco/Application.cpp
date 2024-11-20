#include "Application.h"

Esco::Application::Application() {

}

Esco::Application::~Application() {

}

void Esco::Application::Run() {
	Esco::WindowResizeEvent resizeEvent(1280, 799);
	ESCO_CLIENT_TRACE(resizeEvent);

	while (true);
}