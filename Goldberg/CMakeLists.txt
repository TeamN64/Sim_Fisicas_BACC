cmake_minimum_required(VERSION 3.26)
project(Goldberg)

set(CMAKE_CXX_STANDARD 17)

add_executable(Goldberg main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(Goldberg PRIVATE box2d::box2d)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Goldberg PRIVATE sfml-system sfml-network sfml-graphics sfml-window)