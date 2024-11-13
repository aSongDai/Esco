#pragma once

#include "Core.h"

namespace Esco {

	class ESCO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};


	// TODO: on client
	Application* CreateApplication();

}

