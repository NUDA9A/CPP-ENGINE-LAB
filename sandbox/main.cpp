#include <iostream>

#include <engine/platform/win32/window.hpp>

int main() {
	std::cout << "CPP-ENGINE-LAB started\n";

	engine::WindowConfig window_cfg{ .title = L"CPP-ENGINE-LAB", .width = 1280, .height = 720 };
	engine::Window window(window_cfg);

	while (!window.should_close()) {
		window.poll_events();
	}

	return 0;
}