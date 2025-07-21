cmake_minimum_required(VERSION 3.10)

# Project name and language
project(ProcessMonitor CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required libraries
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

# Find Crow package (moved to root so backend can use it)
find_package(Crow REQUIRED)

# Add the backend subdirectory (where the actual executable is built)
add_subdirectory(backend)