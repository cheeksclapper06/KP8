cmake_minimum_required(VERSION 3.30)
project(KP8 C)

set(CMAKE_C_STANDARD 99)

add_executable(KP8 main.c
        hexnum.h
        complex.h
        calculation.h)
