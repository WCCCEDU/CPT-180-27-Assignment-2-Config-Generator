cmake_minimum_required(VERSION 3.3)
project(Assignment2_Config_Files)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Assignment2_Config_Files ${SOURCE_FILES})