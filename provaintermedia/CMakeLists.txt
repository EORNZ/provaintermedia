cmake_minimum_required(VERSION 3.26)
project(Progetto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Progetto main.cpp
        Book.cpp
        Book.h
        Date.cpp
        Date.h
        BookShelf.cpp
        BookShelf.h)
