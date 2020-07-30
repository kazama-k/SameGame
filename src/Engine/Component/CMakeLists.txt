cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

add_library(
        component_lib
        STATIC
        AnimSpriteComponent.cc
        BGSpriteComponent.cc
        CircleComponent.cc
        InputComponent.cc
        MoveComponent.cc
        SpriteComponent.cc
)

target_link_libraries(component_lib math_lib)
target_link_libraries(component_lib core_lib)

install(TARGETS component_lib DESTINATION ${SAMEGAME_INSTALL_LIB_DIR})