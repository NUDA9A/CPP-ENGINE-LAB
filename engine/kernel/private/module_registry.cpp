#include "module_registry.h"

#include <unordered_set>
#include <algorithm>
#include <cassert>
#include <utility>

namespace engine::kernel {

	/*
	* Registers an owned copy of a valid ModuleDescriptor.
	*
	* Rejects registration after freeze, invalid module metadata,
	* invalid or duplicate dependency declarations, and duplicate ModuleId values.
	* Dependency resolution is intentionally outside this method's scope.
	*
	* On success, returns ModuleRegistryError::OK.
	* On every returned error, the Registry remains unchanged.
	*/
	ModuleRegistryError ModuleRegistry::registerModule(const ModuleDescriptor& mD) {
		const ModuleVersion invalidVersion = ModuleVersion{};

		if (freezed_) {
			return ModuleRegistryError::FreezedRegistry;
		}

		if (mD.mId == 0) {
			return ModuleRegistryError::InvalidModuleId;
		}

		if (mD.mVersion == invalidVersion) {
			return ModuleRegistryError::InvalidModuleVersion;
		}

		if (mD.mGeneration != KERNEL_ABI_GENERATION) {
			return ModuleRegistryError::InvalidModuleAbiGeneration;
		}

		std::unordered_set<ModuleId> combinedDependencies;

		combinedDependencies.reserve(mD.mRequiredDependencies.size() + mD.mOptionalDependencies.size());

		for (const auto& m : mD.mRequiredDependencies) {
			if (m.id == 0) {
				return ModuleRegistryError::InvalidModuleDependencyId;
			}
			if (m.minRequiredVersion == invalidVersion) {
				return ModuleRegistryError::InvalidModuleDependencyVersion;
			}
			combinedDependencies.insert(m.id);
		}

		for (const auto& m : mD.mOptionalDependencies) {
			if (m.id == 0) {
				return ModuleRegistryError::InvalidModuleDependencyId;
			}
			if (m.minRequiredVersion == invalidVersion) {
				return ModuleRegistryError::InvalidModuleDependencyVersion;
			}
			combinedDependencies.insert(m.id);
		}

		if (combinedDependencies.size() != mD.mRequiredDependencies.size() + mD.mOptionalDependencies.size()) {
			return ModuleRegistryError::DuplicatedDependency;
		}

		auto res = registered_modules_.emplace(
			mD.mId,
			mD
		);

		if (!res.second) {
			return ModuleRegistryError::DuplicatedModule;
		}

		return ModuleRegistryError::OK;
	}

	/*
	* Returns a pointer to the Registry-owned ModuleDescriptor,
	* or nullptr if the ModuleId is not registered.
	*
	* The returned pointer remains valid until ModuleRegistry destruction.
	*/
	const ModuleDescriptor* ModuleRegistry::getModule(const ModuleId mId) const {
		if (auto res = registered_modules_.find(mId); res != registered_modules_.end()) {
			return &res->second;
		}

		return nullptr;
	}

	std::size_t ModuleRegistry::getModulesCount() const {
		return registered_modules_.size();
	}

	// Returns reference on the sorted (by ModuleId in incrementing order) registered ModuleDescriptors pointers. Asserts that ModuleRegistry is frozen by freeze() function.
	const std::vector<const ModuleDescriptor*>& ModuleRegistry::getModules() const {
		assert(freezed_);
		return frozen_snapshot_;
	}

	// If Registry is already frozen - no-op. Otherwise, fill frozen_snapshot_ vector and sorts it. Freeze Registry at the end.
	void ModuleRegistry::freeze() {
		if (freezed_) {
			return;
		}

		std::vector<const ModuleDescriptor*> res;
		res.reserve(registered_modules_.size());

		for (const auto& m : registered_modules_) {
			res.push_back(&m.second);
		}

		std::sort(res.begin(), res.end(), [](const ModuleDescriptor* a, const ModuleDescriptor* b) { return a->mId < b->mId; });

		frozen_snapshot_ = std::move(res);

		freezed_ = true;
	}

	bool ModuleRegistry::freezed() const {
		return freezed_;
	}
}