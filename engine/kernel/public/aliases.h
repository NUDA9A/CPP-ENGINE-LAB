#pragma once

#include <cstdint>

namespace engine::kernel {
	using ModuleId = std::uint64_t;
	using ModuleAbiGeneration = std::uint64_t;

	enum class ModuleType { Runtime, Editor, Tool, Game, Test };
}