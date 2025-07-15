cmake_minimum_required(VERSION 3.14)
project(process_monitor)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/websocketpp)


add_executable(process_monitor
    main.cpp
)


