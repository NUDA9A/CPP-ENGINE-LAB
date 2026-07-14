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