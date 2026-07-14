#pragma once

#include "aliases.h"
#include "module_version.h"

namespace engine::kernel {
	struct ModuleDependency {
		ModuleId id{};
		ModuleVersion minRequiredVersion{};
	};
}