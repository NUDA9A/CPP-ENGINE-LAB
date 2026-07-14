add_library(Kernel STATIC private/module_registry.cpp)

target_include_directories(Kernel PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public/>)

target_compile_features(Kernel PUBLIC cxx_std_23)