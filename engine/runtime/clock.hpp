#pragma once

#include <chrono>
#include <cstdint>

#include <engine/runtime/frame_time.hpp>

namespace engine {
	class Clock {
	public:
		Clock();

		FrameTime tick() noexcept;
	private:
		using TimeClock = std::chrono::steady_clock;
		using TimePoint = std::chrono::time_point<TimeClock>;
		using Duration = std::chrono::duration<double>;

		TimePoint start_time_;
		TimePoint prev_frame_;
		std::uint64_t frame_idx_{0};
	};
}