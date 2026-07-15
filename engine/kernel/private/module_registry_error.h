/*
* This file defines ModuleRegistryError - enum describing errors which may occur during usage of ModuleRegistry.
*/


#pragma once

namespace engine::kernel {
	enum class ModuleRegistryError {
		OK,
		FreezedRegistry,
		InvalidModuleId,
		InvalidModuleVersion,
		InvalidModuleAbiGeneration,
		InvalidModuleDependencyId,
		InvalidModuleDependencyVersion,
		DuplicatedDependency,
		DuplicatedModule
	};
}