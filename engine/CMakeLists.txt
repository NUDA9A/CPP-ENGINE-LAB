# add_library(engine_math INTERFACE)
# 
# target_include_directories(engine_math INTERFACE ${PROJECT_SOURCE_DIR})
# 
# target_compile_features(engine_math INTERFACE cxx_std_23)
# 
# add_library(engine_platform STATIC platform/win32/window.cpp platform/win32/window_class.cpp)
# 
# target_include_directories(engine_platform PUBLIC ${PROJECT_SOURCE_DIR})
# 
# target_compile_features(engine_platform PUBLIC cxx_std_23)
# 
# add_library(engine_runtime STATIC runtime/application.cpp "runtime/clock.cpp")
# 
# target_include_directories(engine_runtime PUBLIC ${PROJECT_SOURCE_DIR})
# 
# target_compile_features(engine_runtime PUBLIC cxx_std_23)
# 
# target_link_libraries(engine_runtime PUBLIC engine_platform)

add_subdirectory(kernel)
