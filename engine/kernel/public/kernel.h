/*
 * Defines the current Kernel ABI generation.
 *
 * Modules with a different ABI generation are rejected during registration.
 * This value represents an ABI compatibility epoch, not the semantic version
 * of the Kernel implementation.
 */

#pragma once

#include "aliases.h"

namespace engine::kernel {
	constexpr ModuleAbiGeneration KERNEL_ABI_GENERATION = 1;
}