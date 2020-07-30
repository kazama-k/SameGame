cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

add_library(
        core_lib
        STATIC
        Actor.cc
        Component.cc
        GameCore.cc
)

target_link_libraries(core_lib math_lib)

install(TARGETS core_lib DESTINATION ${SAMEGAME_INSTALL_LIB_DIR})
