cmake_minimum_required(VERSION 3.6)
project(shortest_path)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(shortest_path ${SOURCE_FILES})