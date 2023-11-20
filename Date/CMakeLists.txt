cmake_minimum_required(VERSION 3.26)
project(data)

set(CMAKE_CXX_STANDARD 17)

add_executable(data testerDate.cpp
        Date.h
        Date.cpp
)
