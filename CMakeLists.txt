cmake_minimum_required(VERSION 2.8.12)
project (cs417)

include_directories(include)
include_directories(src)


add_definitions(-std=c++11)

add_executable(./bin/amccann_assignment_1 src/main.cpp)