#pragma once

#include "windows_incl.hpp"

namespace engine {
	inline const wchar_t CLASS_NAME[] = L"CPPEngineLabWindowClass";

	class WindowClass {
	public:
		WindowClass(HINSTANCE hInstance, WNDPROC wndProc);

		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;

		WindowClass(WindowClass&&) = delete;
		WindowClass& operator=(WindowClass&&) = delete;

		~WindowClass() noexcept;

		bool registered() const noexcept;
	private:
		WNDCLASSW wc{};

		bool registered_{ false };
	};
}