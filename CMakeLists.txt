cmake_minimum_required(VERSION 3.7.0)
project (dtmpy
    VERSION 0.1.0
    DESCRIPTION "Python wrapper for dynamic topic modeling"
    LANGUAGES CXX
)

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

add_subdirectory(src)
