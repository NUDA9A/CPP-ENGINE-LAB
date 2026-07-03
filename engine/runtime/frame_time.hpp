#pragma once

#include <cstdint>

namespace engine {
	struct FrameTime {
		double delta_seconds;
		double elapsed_seconds;
		std::uint64_t frame_index;
	};
}