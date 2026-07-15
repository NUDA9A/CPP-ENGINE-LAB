/*
* This file defines ModuleDescriptor - core abstraction of the Module.
* ModuleDescriptor represent metadata describing a Module. ModuleId default value 0 is not valid and not being accepted during Module registration.
*/

#pragma once

#include "aliases.h"
#include "module_version.h"
#include "module_dependency.h"
#include "kernel.h"

#include <vector>

namespace engine::kernel {
	struct ModuleDescriptor {
		ModuleId mId = 0;
		ModuleVersion mVersion = {};
		ModuleType mType = ModuleType::Runtime;
		ModuleAbiGeneration mGeneration = KERNEL_ABI_GENERATION;
		std::vector<ModuleDependency> mRequiredDependencies;
		std::vector<ModuleDependency> mOptionalDependencies;
	};
}