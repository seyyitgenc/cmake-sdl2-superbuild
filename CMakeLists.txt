cmake_minimum_required(VERSION 3.0.0)

project(helloworld)

#include directories
set (I_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/anotherheaders
)

#add all executables
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(helloworld main.cpp ${SOURCE_FILES})

include(FetchContent)

set (FETCHCONTENT_UPDATES_DISCONNECTED ON)
set(FETCHCONTENT_QUIET FALSE)
# sdl2
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL
    GIT_TAG         release-2.26.x
    GIT_PROGRESS    TRUE
)

# sdl2_image
FetchContent_Declare(
    SDL2_IMAGE
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL_image
    GIT_TAG         main
    GIT_PROGRESS    TRUE
)
# sdl2_ttf
FetchContent_Declare(
    SDL2_TTF
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL_ttf
    GIT_TAG         main
    GIT_PROGRESS    TRUE
)

FetchContent_MakeAvailable(SDL2 SDL2_IMAGE SDL2_TTF)

set(SDL_LIBRARIES ${SDL_LIBRARIES} SDL2 SDL2main SDL2_image SDL2_ttf)
target_include_directories("${PROJECT_NAME}" PRIVATE ${I_DIRECTORIES})

target_link_libraries("${PROJECT_NAME}" PRIVATE ${SDL_LIBRARIES})
