add_library(engine_math INTERFACE)

target_include_directories(engine_math INTERFACE ${PROJECT_SOURCE_DIR})

target_compile_features(engine_math INTERFACE cxx_std_23)