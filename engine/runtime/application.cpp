#include "application.hpp"

namespace engine {

    Application::Application(const ApplicationConfig& config)
        : window_(config.window), clock_(config.clock) {}

    Application::~Application() = default;

    int Application::run() {
        while (!window_.should_close()) {
            window_.poll_events();
            auto frame_time = clock_.tick();
        }

        return 0;
    }

} // namespace engine