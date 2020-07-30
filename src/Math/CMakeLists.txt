cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

add_library(
        math_lib
        STATIC
        Vector2.cc
        ${SAMEGAME_INSTALL_INCLUDE_DIR}/Math/MathUtil.h
        ${SAMEGAME_INSTALL_INCLUDE_DIR}/Math/Graph.h
        Random.cc
)

install(TARGETS math_lib DESTINATION ${SAMEGAME_INSTALL_LIB_DIR})
