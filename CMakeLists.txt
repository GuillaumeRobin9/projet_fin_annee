cmake_minimum_required(VERSION 3.13)
project(code C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(code
        file1.c
        file1.h
        file_reader.c
        main.c
        test.c)
