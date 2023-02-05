cmake_minimum_required(VERSION 3.24)
project(project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1
        main.cpp rooms.cpp character.cpp)
