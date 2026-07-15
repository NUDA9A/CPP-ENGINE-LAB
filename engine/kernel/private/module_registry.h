/*
* This file defines ModuleRegistry - abstraction which main point is to register Modules.
* Stores and indexes owned copies of ModuleDescriptor values forming the static module catalog.
* When the Module is being registered, ModuleRegistry obtains ownership on the ModuleDescriptor that represents this Module.
* After all Modules registered this is necessary to call freeze() function, which forbid to register new Modules into this Registry
* and also builds std::vector<const ModuleDescriptor*> frozen_snapshot_ of registered Modules.
* You CAN NOT call getModules() until you called freeze(). getModules() basically returns reference on the frozen_snapshot_ which is not filled until freeze() is called.
* 
* ModuleRegistry garantee that you can not register two same Modules (which have same ModuleId), 
* invalid Modules (invalid ModuleId or ModuleVersion or having invalid ModuleDependency or having same Module as required AND optional dependency).
* ModuleRegistry garantee that after you call freeze(), all ModuleDescriptors addresses fixed in the memory and no more Modules can be registered.
*/

#pragma once

#include <module_descriptor.h>
#include "module_registry_error.h"

#include <unordered_map>
#include <cstddef>
#include <vector>

namespace engine::kernel {
	class ModuleRegistry {
	public:
		ModuleRegistry() = default;
		~ModuleRegistry() = default;

		ModuleRegistry(const ModuleRegistry&) = delete;
		ModuleRegistry& operator=(const ModuleRegistry&) = delete;
		ModuleRegistry(ModuleRegistry&&) = delete;
		ModuleRegistry& operator=(ModuleRegistry&&) = delete;

		ModuleRegistryError registerModule(const ModuleDescriptor& mD);
		const ModuleDescriptor* getModule(const ModuleId) const;
		std::size_t getModulesCount() const;
		const std::vector<const ModuleDescriptor*>& getModules() const;
		void freeze();
		bool freezed() const;
	private:
		bool freezed_{ false };
		std::unordered_map<ModuleId, ModuleDescriptor> registered_modules_;
		std::vector<const ModuleDescriptor*> frozen_snapshot_;
	};
}