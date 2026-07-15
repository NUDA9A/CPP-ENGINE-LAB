/*
* This file contains aliases for ModuleId and ModuleAbiGeneration - need for versioning.
* Also this file defines ModuleType. Architechture goal of this engine is to assemble it with modules. There gonna be default implementations.
* Module can be as some tool or test subsystem, as core subsystem like renderer or physic engine.
*/

#pragma once

#include <cstdint>

namespace engine::kernel {
	using ModuleId = std::uint64_t;
	using ModuleAbiGeneration = std::uint64_t;

	enum class ModuleType { Runtime, Editor, Tool, Game, Test };
}