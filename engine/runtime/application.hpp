#pragma once

#include <engine/platform/win32/window.hpp>

namespace engine {

    struct ApplicationConfig {
        WindowConfig window;
    };

    class Application {
    public:
        explicit Application(const ApplicationConfig& config);
        ~Application();

        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;

        int run();

    private:
        Window window_;
    };

} // namespace engine