cmake_minimum_required(VERSION 3.20)
project(SigmaPong)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
add_executable(SigmaPong Src/main.cpp Src/Game.cpp Src/Game.h Src/TextureManager.cpp Src/TextureManager.h Src/structs.h Src/GameManager.cpp Src/GameManager.h Src/Text.cpp Src/Text.h)
target_link_libraries(SigmaPong ${SDL2_LIBRARIES} -lSDL2_image -lSDL2_ttf)
