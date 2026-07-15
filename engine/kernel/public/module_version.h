/*
* This file defines ModuleVersion (semantic version metadata) - abstraction needed for versioning Modules.
* Module default version 0.0.0 is not valid and not being accepted during Module registration.
*/

#pragma once

#include <cstdint>
#include <string>

namespace engine::kernel {
	struct ModuleVersion {
		std::uint32_t major = 0;
		std::uint32_t minor = 0;
		std::uint32_t patch = 0;

		std::string getVersion() const {
			return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
		}

		bool operator==(const ModuleVersion& other) const {
			return major == other.major && minor == other.minor && patch == other.patch;
		}
	};
}