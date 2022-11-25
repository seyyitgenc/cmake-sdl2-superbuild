cmake_minimum_required(VERSION 3.0.0)

project(helloworld)

add_subdirectory(${PROJECT_SOURCE_DIR}/SDL)

add_executable(${PROJECT_NAME} helloworld.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC SDL/include
)

link_directories(${PROJECT_NAME}
    PUBLIC SDL/src
    PUBLIC SDL/
)

target_link_libraries(${PROJECT_NAME} SDL2)