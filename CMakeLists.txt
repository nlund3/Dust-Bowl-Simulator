cmake_minimum_required(VERSION 3.13.0)

set(PROJECT_NAME DustBowSimulator)
project(${PROJECT_NAME} VERSION 0.1.0)

add_library(dust-bowl-game)

target_include_directories(
    dust-bowl-game
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

add_subdirectory(src)
add_subdirectory(tests)