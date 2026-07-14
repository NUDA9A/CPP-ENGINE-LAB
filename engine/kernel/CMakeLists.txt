add_library(Kernel INTERFACE)

target_include_directories(Kernel INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public/>)

target_compile_features(Kernel INTERFACE cxx_std_23)