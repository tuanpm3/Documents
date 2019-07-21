cmake_minimum_required(VERSION 2.6)

project(msg_queue)

#include dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#build target
add_executable(proc1.exe proc1.cpp)
add_executable(proc2.exe proc2.cpp)