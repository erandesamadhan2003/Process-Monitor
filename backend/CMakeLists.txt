cmake_minimum_required(VERSION 3.10)

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(${PROJECT_NAME} simple_server.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE pthread)

# Copy config files to build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config/config.json 
               ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/config.json COPYONLY)