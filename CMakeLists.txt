cmake_minimum_required(VERSION 3.30)
project(Library)

set(CMAKE_CXX_STANDARD 20)

add_executable(Library
        main.cpp
        Date.cpp
        Date.h
        Books.cpp
        Books.h
        Customer.cpp
        Customer.h
        LibraryManager.cpp
        LibraryManager.h)
