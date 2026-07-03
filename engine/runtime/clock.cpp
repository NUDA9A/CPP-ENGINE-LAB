#include "clock.hpp"

namespace engine {
	Clock::Clock() {
		const TimePoint now = TimeClock::now();

		start_time_ = now;
		prev_frame_ = now;
	}

	FrameTime Clock::tick() noexcept {
		const TimePoint now = TimeClock::now();

		const Duration delta = now - prev_frame_;
		const Duration elapsed = now - start_time_;

		prev_frame_ = now;

		FrameTime frame_time{
			.delta_seconds = delta.count(),
			.elapsed_seconds = elapsed.count(),
			.frame_index = frame_idx_
		};

		++frame_idx_;

		return frame_time;
	}
}