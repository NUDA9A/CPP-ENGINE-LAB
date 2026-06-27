#pragma once

#include "windows_incl.hpp"


namespace engine {
    struct WindowConfig {
        const wchar_t* title;
        int width;
        int height;
    };

    class Window {
    public:
        explicit Window(const WindowConfig& config);
        ~Window();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        void poll_events();
        bool should_close() const noexcept;

    private:
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        void destroy_window();
        LRESULT handle_keyboard(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

        bool should_close_{ false };
        HINSTANCE hInstance_{nullptr};
        int width_{};
        int height_{};
        HWND hwnd_{nullptr};
    };

} // namespace engine