# Version 3.10 or higher is required
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(ProcessMonitor CXX)

# add the C++ standard
set(CMAKE_CXX_STANDARD 17)  

# Ensure the C++ standard is required
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# execute the backend CMakeLists.txt
add_executable(ProcessMonitor main.cpp)