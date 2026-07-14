#pragma once

namespace engine::kernel {
	enum class ModuleRegistryError {
		OK, FreezedRegistry, InvalidModuleId, InvalidModuleVersion, InvalidModuleAbiGeneration, InvalidModuleDependencyId, InvalidModuleDependencyVersion, DuplicatedDependency, DuplicatedModule
	};
}