cmake_minimum_required(VERSION 3.26)
project(hola_nuevo_nevo_mundo)

set(CMAKE_CXX_STANDARD 17)

add_executable(hola_nuevo_nevo_mundo main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(hola_nuevo_nevo_mundo PRIVATE box2d::box2d)