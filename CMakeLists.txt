cmake_minimum_required(VERSION 3.26)
project(control1_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(control1_1 main.cpp
        tableros.h
        fichas.h
        lectura.h
        menu.h)
