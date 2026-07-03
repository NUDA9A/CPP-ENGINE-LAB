#include <iostream>

#include <engine/runtime/application.hpp>
#include <engine/runtime/clock.hpp>

int main() {
	std::cout << "CPP-ENGINE-LAB started\n";

	engine::Application app({ .window = {
		.title = L"CPP-ENGINE-LAB",
		.width = 1920,
		.height = 1080
		},
		.clock = {}
		});

	return app.run();
}