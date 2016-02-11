cmake_minimum_required(VERSION 3.3)
project(Assignment_2_File_Generator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Assignment_2_File_Generator ${SOURCE_FILES})