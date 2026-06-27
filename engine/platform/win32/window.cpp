#include "window.hpp"
#include "window_class.hpp"

#include <stdexcept>
#include <cassert>

namespace engine {
    LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        if (uMsg == WM_NCCREATE) {
            CREATESTRUCTW* create_struct = reinterpret_cast<CREATESTRUCTW*>(lParam);
            Window* window = reinterpret_cast<Window*>(create_struct->lpCreateParams);
            if (window == nullptr) {
                return FALSE;
            }
            SetLastError(0);
            auto old_value = SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
            if (old_value == 0 && GetLastError() != 0) {
                window->should_close_ = true;
                return FALSE;
            }
            window->hwnd_ = hwnd;
            return TRUE;
        }

        Window* window = reinterpret_cast<Window*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));

        if (window == nullptr) {
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
        }

        switch (uMsg)
        {
        case WM_CLOSE:
            window->should_close_ = true;
            break;
        case WM_KEYDOWN:
            return window->handle_keyboard(hwnd, uMsg, wParam, lParam);
        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
        }

        return 0;
    }

    LRESULT Window::handle_keyboard(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (wParam) {
        case VK_ESCAPE:
            should_close_ = true;
            break;
        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
        }

        return 0;
    }

    static WindowClass& window_class(HINSTANCE hInstance, WNDPROC wndProc) {
        static WindowClass instance(hInstance, wndProc);
        return instance;
    }

	Window::Window(const WindowConfig& config) : hInstance_(GetModuleHandleW(nullptr)), width_(config.width), height_(config.height) {
        assert(config.title != nullptr);
        WindowClass& wc = window_class(hInstance_, Window::WindowProc);

        if (!wc.registered()) {
            throw std::runtime_error("Can not register window!");
        }

        hwnd_ = CreateWindowExW(0, CLASS_NAME, config.title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width_, height_, nullptr, nullptr, hInstance_, static_cast<void*>(this));

        if (hwnd_ == nullptr) {
            throw std::runtime_error("Can not create window!");
        }

        ShowWindow(hwnd_, SW_NORMAL);
	}

    void Window::destroy_window() {
        should_close_ = true;
        if (hwnd_ != nullptr) {
            DestroyWindow(hwnd_);
        }
        hwnd_ = nullptr;
    }

    Window::~Window() {
        destroy_window();
    }

    void Window::poll_events() {
        MSG msg{};
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) > 0) {
            if (msg.message == WM_QUIT) {
                should_close_ = true;
                return;
            }
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }

    bool Window::should_close() const noexcept {
        return should_close_;
    }
}