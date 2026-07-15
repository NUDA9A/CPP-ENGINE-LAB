/*
 * Defines a module-level dependency requirement.
 *
 * A dependency identifies another module and specifies its minimum required
 * semantic version. Dependency presence and version compatibility are resolved
 * during dependency graph construction, not by ModuleRegistry.
 */

#pragma once

#include "aliases.h"
#include "module_version.h"

namespace engine::kernel {
	struct ModuleDependency {
		ModuleId id{};
		ModuleVersion minRequiredVersion{};
	};
}