#include <Esco.h>

class ESCO_API Sandbox : public Esco::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};


Esco::Application* Esco::CreateApplication() {
	return new Sandbox();
}