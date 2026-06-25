cmake_minimum_required(VERSION 3.28)

project(CPP_ENGINE_LAB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(engine)
add_subdirectory(sandbox)

include(CTest)

if (BUILD_TESTING)
	add_subdirectory(tests)
endif()