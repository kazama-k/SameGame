cmake_minimum_required(VERSION 3.16)
project(src)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
#find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)
#find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SAMEGAME_INSTALL_INCLUDE_DIR})

add_subdirectory(Engine)
add_subdirectory(Math)
add_subdirectory(SameAction)

add_executable(SameActionGame SameActionGame.cc)

target_link_libraries(same_action_lib ${SDL2_LIBRARIES})
#target_link_libraries(project ${SDL2_TTF_LIBRARIES})
target_link_libraries(same_action_lib ${SDL2_IMAGE_LIBRARIES})

target_link_libraries(same_action_lib math_lib)
target_link_libraries(same_action_lib core_lib)
target_link_libraries(same_action_lib component_lib)

target_link_libraries(SameActionGame same_action_lib)
