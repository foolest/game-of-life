cmake_minimum_required(VERSION 3.12)
project(game-of-life)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Set the build directory to a "build" subfolder
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# Find and configure any necessary libraries
# Example: find_package(YourLibrary REQUIRED)

# Include directories for header files
include_directories(include)

# Add your source files
add_executable(game-of-life
    src/main.cpp
	src/Game_Board.cpp
    # Add any other source files here
)

# If you have any additional libraries to link against, do it here
# Example: target_link_libraries(your_executable_name YourLibrary)

# Optionally, if you want to install your executable, headers, or libraries
# install(TARGETS your_executable_name DESTINATION bin)
# install(FILES include/mylibrary.hpp DESTINATION include)
# install(TARGETS YourLibrary DESTINATION lib)

# Additional configurations if needed
# Example: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# You can also add tests, examples, and other subdirectories here if needed

# Define a custom target to build and run the executable
add_custom_target(run
    COMMAND game-of-life
    DEPENDS game-of-life
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMMENT "Running game of life..."
)
