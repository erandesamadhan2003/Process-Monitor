# ProcessMonitor - Main CMakeLists.txt
cmake_minimum_required(VERSION 3.15)

# Project configuration
project(ProcessMonitor 
    VERSION 1.0.0
    DESCRIPTION "Process Monitor & Auto-Restarter"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler-specific options
if(MSVC)
    # Visual Studio compiler flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /O2")
else()
    # GCC/Clang compiler flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
endif()

# Find required packages using vcpkg
find_package(nlohmann_json CONFIG REQUIRED)
find_package(httplib CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# Platform detection
if(WIN32)
    add_definitions(-DWINDOWS_PLATFORM)
elseif(UNIX)
    add_definitions(-DLINUX_PLATFORM)
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/*.h"
)

# Remove platform-specific files based on current platform
if(WIN32)
    file(GLOB_RECURSE LINUX_SOURCES "src/platform/linux/*.cpp")
    list(REMOVE_ITEM SOURCES ${LINUX_SOURCES})
else()
    file(GLOB_RECURSE WINDOWS_SOURCES "src/platform/windows/*.cpp")
    list(REMOVE_ITEM SOURCES ${WINDOWS_SOURCES})
endif()

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    nlohmann_json::nlohmann_json
    httplib::httplib
    spdlog::spdlog
)

# Platform-specific libraries
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32 winmm)
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
endif()

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Enable testing
enable_testing()

# Add subdirectories
add_subdirectory(tests)

# Installation
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)