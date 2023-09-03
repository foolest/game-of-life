cmake_minimum_required(VERSION 3.12)
project(game-of-life)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)


include_directories(include)

add_executable(game-of-life
    src/main.cpp
	src/Game_Board.cpp
)

add_custom_target(run
    COMMAND game-of-life
    DEPENDS game-of-life
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMMENT "Running game of life..."
)
