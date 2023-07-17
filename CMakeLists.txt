set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.12)

project(CLM)

set(
    MAIN 
    src/main.cpp
)

set(
    WINDOW 
    src/window/constructor.cpp
    src/window/destructor.cpp
    src/window/status.cpp
    src/window/running.cpp
)

set(
    OBJECT 
    src/object/constructor.cpp 
    src/object/destructor.cpp
    src/object/cropping.cpp
    src/object/locating.cpp
    src/object/coloring.cpp
    src/object/rendering.cpp 
    src/object/shape.cpp 
    src/object/external_storage.cpp
    src/object/visible.cpp
)

set( 
    CONTAINER 
    src/container/constructor.cpp
    src/container/destructor.cpp
    src/container/rendering.cpp
)

add_executable(${PROJECT_NAME} ${MAIN} ${WINDOW} ${OBJECT} ${CONTAINER})

target_include_directories(${PROJECT_NAME} PRIVATE include/)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_definitions(${PROJECT_NAME} PRIVATE IMGDIR="../img/")

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} SDL2_image SDL2_ttf ${CMAKE_DL_LIBS} pthread)
