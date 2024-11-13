#include <Esco.h>

class Sandbox : public Esco::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};


Esco::Application* Esco::CreateApplication() {
	return new Sandbox();
}