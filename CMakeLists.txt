cmake_minimum_required(VERSION 3.20)
project(SigmaEngine)

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
add_executable(SigmaPong Src/main.cpp Src/Game.cpp Src/Game.h Src/TextureManager.cpp Src/TextureManager.h Src/structs.h Src/GameManager.cpp Src/GameManager.h)
target_link_libraries(SigmaPong ${SDL2_LIBRARIES} -lSDL2_image -lSDL2_ttf)
