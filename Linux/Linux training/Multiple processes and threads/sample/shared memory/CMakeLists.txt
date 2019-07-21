cmake_minimum_required(VERSION 2.6)

project(share_mem)

#include dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#build lib
add_library(sem sem.cpp)

#build target
add_executable(proc1.exe proc1.cpp)
target_link_libraries(proc1.exe sem pthread)

add_executable(proc2.exe proc2.cpp)
target_link_libraries(proc2.exe sem pthread)