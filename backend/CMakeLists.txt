# Create backend executable with all source files
add_executable(ProcessMonitorBackend
    main.cpp
    # utils/logger.cpp  # Uncomment when you add this file
)

# Include directories (for header files)
target_include_directories(ProcessMonitorBackend
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    # ${CMAKE_CURRENT_SOURCE_DIR}/utils  # Uncomment when you add utils
)

# Link required libraries
target_link_libraries(ProcessMonitorBackend
    PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
    ZLIB::ZLIB
    pthread
    Crow::Crow
)