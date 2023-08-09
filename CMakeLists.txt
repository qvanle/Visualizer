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
    src/window/updating.cpp
    src/window/rendering.cpp
    src/window/event.cpp
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
    src/object/font.cpp
)

set( 
    SPRITE 
    src/sprite/constructor.cpp
    src/sprite/destructor.cpp
    src/sprite/rendering.cpp
    src/sprite/textbox.cpp
    src/sprite/locating.cpp
    src/sprite/aligning.cpp
)

set( 
    SERVICES
    src/services/json.cpp
    src/services/number.cpp
    src/services/random.cpp
)

set( 
    DISPLAY 
    src/display/constructor.cpp 
    src/display/destructor.cpp
    src/display/rendering.cpp
    src/display/event.cpp
)

set (
    BUTTON 
    src/button/constructor.cpp 
    src/button/destructor.cpp 
    src/button/rendering.cpp
    src/button/action.cpp
    src/button/mouse_action.cpp
    src/button/event.cpp
)
set ( 
    DATA_STRUCTURES 
    src/data_structures/constructor.cpp 
    src/data_structures/destructor.cpp
    src/data_structures/rendering.cpp
    src/data_structures/operator.cpp
    src/data_structures/hash_table.cpp
    src/data_structures/heap.cpp 
    src/data_structures/AVL.cpp
    src/data_structures/btree4th.cpp 
    src/data_structures/trie.cpp
    src/data_structures/graph.cpp
    src/data_structures/event.cpp
)

set ( 
    INPUTBOX 
    src/inputbox/constructor.cpp
    src/inputbox/destructor.cpp
    src/inputbox/rendering.cpp
    src/inputbox/event.cpp
    src/inputbox/typing.cpp
    src/inputbox/operator.cpp
)

add_executable(${PROJECT_NAME} ${MAIN} ${WINDOW} ${OBJECT} ${SPRITE} ${SERVICES} ${DISPLAY} ${BUTTON} ${DATA_STRUCTURES} ${INPUTBOX})

target_include_directories(${PROJECT_NAME} PRIVATE include/)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_definitions(${PROJECT_NAME} PRIVATE IMGDIR="../img/")

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} SDL2_image SDL2_ttf ${CMAKE_DL_LIBS} pthread)
