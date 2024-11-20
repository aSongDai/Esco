#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Esco/Log.h"

namespace Esco {

	class ESCO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	// TODO: on client
	Application* CreateApplication();

}

