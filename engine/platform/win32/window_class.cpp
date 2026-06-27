#include "window_class.hpp"

namespace engine {
	WindowClass::WindowClass(HINSTANCE hInstance, WNDPROC wndProc) {
        wc.lpfnWndProc = wndProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = CLASS_NAME;

        if (RegisterClassW(&wc) == 0) {
            return;
        }

        registered_ = true;
	}

    WindowClass::~WindowClass() noexcept {
        if (registered_) {
            UnregisterClassW(CLASS_NAME, wc.hInstance);
        }
    }

    bool WindowClass::registered() const noexcept {
        return registered_;
    }
}