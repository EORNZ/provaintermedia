cmake_minimum_required(VERSION 3.26)
project(Progetto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Progetto main.cpp
        src/Book.cpp
        include/Book.h
        src/Date.cpp
        src/BookShelf.cpp
        include/BookShelf.h
        include/Date.h)
