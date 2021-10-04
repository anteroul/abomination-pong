cmake_minimum_required(VERSION 3.20)
project(SigmaEngine)

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
add_executable(SigmaEngine main.cpp game.cpp game.h)
target_link_libraries(SigmaEngine ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
