cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

add_library(
        same_action_lib
        STATIC
        Game.cc
        Actor/ShipActor.cc
        Actor/LaserActor.cc
        Actor/SpaceBGActor.cc
        Actor/StarBGActor.cc
)

install(TARGETS same_action_lib DESTINATION ${SAMEGAME_INSTALL_LIB_DIR})
